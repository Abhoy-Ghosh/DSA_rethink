// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& arr){
    int n = arr.size();
  
    int swapPrev ,sp;
    int swapNext, sn;
    
    bool descendingOrderFlag =true;
    
    int lowestDiff = INT_MAX;
    
    for(int i = n-2; i >= 0;i--){
        if(arr[i] < arr[i+1]){
            swapPrev = arr[i];
            sp = i;// finding breakpoint
            descendingOrderFlag =false;
            break; //The breakpoint must be the first one from the right.
        }
    }
    
    if(descendingOrderFlag != false){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    
    for(int j = sp+1; j < n;j++){
        int diff = arr[j] -swapPrev;
        
        if(diff > 0 && lowestDiff >= diff){
            lowestDiff = diff;
            swapNext = arr[j];
            sn = j;
        }
    }

  
// This is the standard solution.
  // Search from the right.

// It works because the suffix is already in non-increasing order.
//   for(int j = n-1; j > sp; j--){

//     if(arr[j] > arr[sp]){
//         sn = j;
//         break;
//     }
// }
 
    swap(arr[sp],arr[sn]);
    
    reverse(arr.begin()+sp+1 , arr.end());
    
    return arr;
}



void printArray(vector<int>& arr){

    cout << "[ ";

    for(int x : arr)
        cout << x << " ";

    cout << "]";
}



int main(){

    vector<vector<int>> tests = {

        {1,2,3},
        {3,2,1},
        {1,1,5},
        {1,3,2},
        {2,1,3},
        {1,5,4,3,2},
        {1,3,5,4,2},
        {2,3,1},
        {1},
        {},
        {1,2},
        {2,1},
        {1,2,3,6,5,4},
        {2,2,0,4,3,1},
        {1,4,3,2},
        {1,5,1},
        {2,3,1,3,3}
    };

    for(int i = 0; i < tests.size(); i++){

        cout << "----------------------------\n";
        cout << "Test Case " << i + 1 << endl;

        cout << "Before : ";
        printArray(tests[i]);
        cout << endl;

        vector<int> ans = nextPermutation(tests[i]);

        cout << "After  : ";
        printArray(ans);
        cout << endl << endl;
    }

    return 0;
}
