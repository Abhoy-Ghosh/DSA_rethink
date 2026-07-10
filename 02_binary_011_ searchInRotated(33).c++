// 33. Search in Rotated Sorted Array
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

// Step 1
// ↓
// Find mid
// Step 2
// ↓
// Which half is sorted?
// Left?
// Right?
// Step 3
// ↓
// Does the target belong to that sorted half?
// YES
// ↓
// Go there
// NO
// ↓
// Go to the other half

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// {4,5,6,7,1,2,3}


int searchInRotated(vector<int> arr, int target){
    int n = arr.size();
    
    int low = 0;
    int high = n-1;
    
    while(low<= high){
        int mid = low+((high-low)/2);
        
        if(arr[mid] == target) return mid;
        
        // right half
       if(arr[mid] <= arr[high]){
            if(arr[mid]<target  && target <= arr[high]){
                low = mid+1;
            }
            else high =mid-1;
        } 
        //left half
        // if(arr[mid] >= arr[low]){
        else{
            if(arr[mid] > target && target >= arr[low]){
                high =mid-1;
            }
            else low = mid+1;
        }
        
    }
    return -1;
}
int main() {
    
    vector<int> vec ={4,5,6,7,1,2,3};
    int ans = searchInRotated(vec,30);
    cout << ans;
    return 0;
}
