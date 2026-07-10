#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinRotated(vector<int>& arr){

    int low = 0;
    int high = arr.size()-1;

    int ans = INT_MAX;

    while(low <= high){

        int mid = low + (high-low)/2;

        // Current search space already sorted
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        // Left half is sorted
        if(arr[mid] >= arr[low]){

            ans = min(ans, arr[low]);

            low = mid + 1;
        }

        // Pivot lies in left half
        else{

            ans = min(ans, arr[mid]);

            high = mid - 1;
        }
    }

    return ans;
}

int main(){

    vector<int> arr = {6,7,8,9,1,2,4};

    cout << findMinRotated(arr);
}
