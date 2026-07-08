// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int left, int right, int target){
    // element not found after traversal
    if (left > right) return -1;
    
    int mid = (left+right)/2;
        
    if (arr[mid] == target) return mid;
        
    if(arr[mid] < target) return binarySearch(arr,mid+1, right,target);
        
    if(arr[mid] > target) return binarySearch(arr,left , mid-1,target);
    
    return 0;
}

int main() {

    vector<pair<vector<int>, int>> testCases = {

        {
            {1, 3, 5, 7, 9},
            5
        },

        {
            {1, 3, 5, 7, 9},
            1
        },

        {
            {1, 3, 5, 7, 9},
            9
        },

        {
            {1, 3, 5, 7, 9},
            6
        },

        {
            {10},
            10
        },

        {
            {10},
            5
        },

        {
            {-10, -5, -2, 0, 4, 8},
            -5
        },

        {
            {-10, -5, -2, 0, 4, 8},
            8
        },

        {
            {-10, -5, -2, 0, 4, 8},
            100
        },

        {
            {2, 4, 6, 8, 10, 12, 14},
            12
        }
    };

    for (int i = 0; i < testCases.size(); i++) {
     
      int n = testCases[i].first.size();
        int left =0;
        int right =n-1;
        
        
        cout << "============================\n";
        cout << "Test Case " << i + 1 << endl;

        cout << "Array : ";

        for (int x : testCases[i].first)
            cout << x << " ";

        cout << "\nTarget : " << testCases[i].second << endl;

        int ans = binarySearch(testCases[i].first, left, right, testCases[i].second);

        cout << "Returned Index : " << ans << endl;
    }

    return 0;
}
