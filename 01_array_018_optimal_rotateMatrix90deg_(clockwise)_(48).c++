// 48. Rotate Image

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
  
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]


#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void printMatrix(vector<vector<int>>& mtx){
    int nrow = mtx.size();
    int ncol= mtx[0].size();
    
    cout<< "print while traversal row wise -> " <<endl; 
    
    for(int i = 0; i< nrow; i++){
        for(int j = 0; j<ncol; j++){
            cout<<mtx[i][j] << " ";
        }
        cout<< endl;
    }
    cout <<endl;
    return;
}



void printMatrixCol(vector<vector<int>>& mtx){
    int nrow = mtx.size();
    int ncol= mtx[0].size();
    
    cout<< "print while traversal column wise -> "<< endl ;

    for(int i = 0; i < ncol; i++){
        for(int j = 0; j < nrow; j++){
            cout<<mtx[j][i] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
    return;
}


vector<vector<int>> transposeMatrix(vector<vector<int>>& mtx){
    int nrow = mtx.size();
    int ncol= mtx[0].size();
    
    for( int i = 0; i < nrow; i++){
        for(int j = 0; j < ncol; j++){
            if(j > i){ // only upper triangle need to traverse ..because we want swap just one time
            swap(mtx[i][j], mtx[j][i]);
            }
         }
    }
    // cout << endl;
    
    return mtx;
}


vector<vector<int>> rotateMatrix90deg(vector<vector<int>>& mtx){
    int nrow = mtx.size();
    
    mtx  = transposeMatrix(mtx);
    for(int i = 0; i < nrow; i++){
        reverse(mtx[i].begin(), mtx[i].end());
    }
    
    return mtx;
}

int main(){
    
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout <<"Original Matrix:" << endl;
    printMatrix(m);
    cout << "===========================" << endl;
    
    cout << "Transposed Matrix:" <<endl;
    printMatrixCol(m);
    cout << "===========================" << endl;
    
    // cout << "Transposed Matrix:" <<endl;
    // m = transposeMatrix(m);
    // printMatrix(m);
    // return 0;
    
    cout << "Rotate matrix by 90 degrees :" <<endl;
    m = rotateMatrix90deg(m);
    printMatrix(m);
    return 0;
}



