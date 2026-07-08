class Solution {
public:

    vector<vector<int>> transposeMatrix(vector<vector<int>>& mtx){
        int nrow = mtx.size();
        int ncol = mtx[0].size();

        for(int i = 0; i < nrow; i++){
            for(int j = 0; j < ncol; j++){
                // only upper triangle need to traverse because we want swap just one time
                if(j > i){
                    swap(mtx[i][j], mtx[j][i]);
                }
            }
        }

        return mtx;
    }

    vector<vector<int>> rotateMatrix90AntiClockwise(vector<vector<int>>& mtx){

        int ncol = mtx[0].size();

        mtx = transposeMatrix(mtx);

        // Reverse every column
        for(int j = 0; j < ncol; j++){

            int top = 0;
            int bottom = mtx.size() - 1;

            while(top < bottom){
                swap(mtx[top][j], mtx[bottom][j]);
                top++;
                bottom--;
            }
        }

        return mtx;
    }
};




// Original

// 1 2 3
// 4 5 6
// 7 8 9

// ↓

// Reverse Rows

// 3 2 1
// 6 5 4
// 9 8 7

// ↓

// Transpose

// 3 6 9
// 2 5 8
// 1 4 7
