// input:
  // vector<vector<int>> matrix = {
  //       {1,2,3,10},
  //       {4,5,6,11},
  //       {7,8,9,12},
  //       {20,21,22,23}
  //   };

//output:
// 1 2 3 10 11 12 23 22 21 20 7 4 5 6 9 8 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//         left        right
// top-    1   2   3   4
//         5   6   7   8
//         9   10  11  12
// bottom- 13  14  15  16




vector<int> spiralMatrix(vector<vector<int>> mtx){
    
    int nrow= mtx.size();
    int ncol = mtx[0].size();
    
    int left= 0;
    int right = ncol-1;
    
    int top = 0;
    int bottom = nrow-1;
    
    int i,j;
    
    vector<int> spiral;
  
  
 while(top<= bottom && left<=right){  
    for(i = left; i<= right; i++){
        cout << mtx[top][i] << " ";
        spiral.push_back(mtx[top][i]);
    }
    top++; 
    
    for(i = top; i <= bottom; i++){
        cout << mtx[i][right] << " ";
        spiral.push_back(mtx[i][right]);
    }
    right--;

if(top<= bottom){
    for(i = right; i >= left; i--){
        cout <<mtx[bottom][i] <<" ";
        spiral.push_back(mtx[bottom][i]);
    }
    bottom--; 
}

if(left<=right){
    for(i = bottom; i >= top; i--){
        cout << mtx[i][left] << " ";
        spiral.push_back(mtx[i][left]);
        }
    }
    left++;
  }
  
  cout<<endl;
  
    return spiral;
    
}

int main() {
    
    vector<vector<int>> matrix = {
        {1,2,3,10},
        {4,5,6,11},
        {7,8,9,12},
        {20,21,22,23}
    };
    
    vector<int> ans =spiralMatrix(matrix);
    
    int n = ans.size();   
        
    for(int i= 0; i< n; i++){
        cout<< ans[i]<< " ";
    }

    return 0;
}
