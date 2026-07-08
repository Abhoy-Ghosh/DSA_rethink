// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int target){
    int n = arr.size();
     //long long for edge case like both left and right pointing int_max
    // preventing overflow
    long long left = 0;
    long long right = n-1;
    
    while(left <= right){
        int mid = (left+right)/2;
        
        if (arr[mid] == target) return mid;
        
        else if(arr[mid] < target) left = mid+1;
        
        else right = mid-1;
    }
    
    return -1;
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

        cout << "============================\n";
        cout << "Test Case " << i + 1 << endl;

        cout << "Array : ";

        for (int x : testCases[i].first)
            cout << x << " ";

        cout << "\nTarget : " << testCases[i].second << endl;

        int ans = binarySearch(testCases[i].first, testCases[i].second);

        cout << "Returned Index : " << ans << endl;
    }

    return 0;
}
