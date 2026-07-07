
#include <iostream>
#include<vector>
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
            if( i == j || j < i){
                
            }
            else if(j > i){ // only upper triangle need to traverse ..because we want swap just one time
            swap(mtx[i][j], mtx[j][i]);
            }
         }
    }
    // cout << endl;
    
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
    
    cout << "Transposed Matrix:" <<endl;
    m = transposeMatrix(m);
    printMatrix(m);
    return 0;
}
// vector<vector<int>> setMatrixZero(vector<vector<int>>& mtx)


