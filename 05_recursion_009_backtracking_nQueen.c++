// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool safe(int row, int col, vector<vector<int>>& board, int n){
    int ROW = row;
    int COL = col;
    
    // left row (as we place queen left to right)
    
    while(col >= 0){ // row wise moving -> row is constant
        if(board[row][col] == 1) return false;
        col--;
    }
    col = COL;
    
    // upper left diagonal
    while(col >= 0 && row >= 0){
        if(board[row][col] == 1) return false;
        col--;
        row--;
    }
    row = ROW;
    col = COL;
    
    // lower left diagonal
    while(col >=0  && row < n){
        if(board[row][col] == 1) return false;
        col--;
        row++;
    }
    row = ROW;
    col = COL;
    
    return true;
    
}



void nQueen(int col,vector<vector<int>>& board, vector<vector<vector<int>>>& ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++){
        if(safe(row, col, board, n)){
            board[row][col] = 1; // forward rec
            nQueen(col+1,board, ans, n);
            board[row][col] = 0; // backtracking
        }
    }
}


int main() {
   int n = 8;
   vector<vector<int>> board(n,vector<int>(n,0));
   int col= 0;
   vector<vector<vector<int>>> ans;
   
  nQueen(col,board, ans, n);
   
   for(auto row : ans){
      for(auto cell : row){
          for(auto it : cell){
          cout << it<< " ";
              
          }
          cout<< endl;
      }
      cout<< endl;
   }
cout << ans.size();
    return 0;
}
