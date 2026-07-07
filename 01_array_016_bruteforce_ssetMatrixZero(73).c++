//73. Set Matrix Zeroes
//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//You must do it in place.

//Example 1:
//Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[1,0,1],[0,0,0],[1,0,1]]

//Example 2:
//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


// Scanning: O(m × n)
// Zeroing rows: O(k × n)
// Zeroing columns: O(k × m)

// where k is the number of original zeros.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrixZero(vector<vector<int>>& mtx){
    int row = mtx.size();
    int col = mtx[0].size();
    vector<int> colZ,rowZ;
    for(int r=0; r < row; r++){
        for(int c=0; c<col; c++){
            if(mtx[r][c] == 0){
                colZ.push_back(c);
                rowZ.push_back(r);
            }
        }
    }
    
    for(int i = 0; i <rowZ.size(); i++){
        int currRow = rowZ[i];
        
        for(int j = 0; j <col; j++){
            mtx[currRow][j] = 0;
        }
    }
    
    
    for(int i = 0; i <colZ.size(); i++){
        int currCol = colZ[i];
        
        for(int j = 0; j <row; j++){
            mtx[j][currCol] = 0;
        }
    }

    return mtx;
}

int main() {

    vector<pair<string, vector<vector<int>>>> testCases = {

        {
            "Test Case 1: One zero in the middle",
            {
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
            }
        },

        {
            "Test Case 2: Zero at the top-left corner",
            {
                {0, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            }
        },

        {
            "Test Case 3: Multiple zeros",
            {
                {1, 2, 0},
                {4, 5, 6},
                {0, 8, 9}
            }
        },

        {
            "Test Case 4: No zeros",
            {
                {1, 2},
                {3, 4}
            }
        },

        {
            "Test Case 5: All zeros",
            {
                {0, 0},
                {0, 0}
            }
        },

        {
            "Test Case 6: Single row",
            {
                {1, 0, 3, 4}
            }
        },

        {
            "Test Case 7: Single column",
            {
                {1},
                {0},
                {3},
                {4}
            }
        }
    };

    for (auto &test : testCases) {

        cout << "=====================================\n";
        cout << test.first << endl;
        cout << "Output:\n";

        vector<vector<int>> ans = setMatrixZero(test.second);

        for (auto &row : ans) {
            for (int x : row)
                cout << x << " ";
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}


