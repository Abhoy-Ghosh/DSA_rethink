// 81. Search in Rotated Sorted Array II
// There is an integer array nums sorted in non-decreasing order (duplicates allowed).
// Before being passed to your function, nums is rotated at an unknown pivot.
// Given the rotated array and a target, return true if the target exists,
// otherwise return false.

// ------------------------------------------------------------
// Difference from LeetCode 33
// ------------------------------------------------------------
//
// LeetCode 33:
// - Distinct elements
// - One half is ALWAYS clearly sorted.
//
// LeetCode 81:
// - Duplicate elements allowed.
// - Sometimes duplicates hide which half is sorted.
//
// Example:
//
// 1 0 1 1 1
// ^   ^   ^
// L   M   H
//
// arr[low] == arr[mid] == arr[high]
//
// Cannot determine whether the left or right half is sorted.
//
// Solution:
// Remove duplicates from both ends.
//
// low++;
// high--;
//
// Then continue exactly like LeetCode 33.
//
// ------------------------------------------------------------
//
// Algorithm
//
// Step 1
// ↓
// Find mid
//
// Step 2
// ↓
// Target found ?
//
// YES
// ↓
// Return true
//
// NO
// ↓
//
// Step 3
// ↓
// Are low, mid and high equal ?
//
// arr[low] == arr[mid] == arr[high]
//
// YES
// ↓
// low++
// high--
// continue;
//
// NO
// ↓
//
// Step 4
// ↓
// Which half is sorted ?
//
// Left ?
// Right ?
//
// Step 5
// ↓
// Does the target belong to that sorted half ?
//
// YES
// ↓
// Search that half
//
// NO
// ↓
// Search the other half
//
// ------------------------------------------------------------
//
// Worst Case
//
// 1 1 1 1 1 1 1
//
// Every iteration
//
// low++
// high--
//
// Therefore
//
// Worst Case = O(n)
//
// Average Case = O(log n)
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool searchInRotated(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // Target Found
        if (arr[mid] == target)
            return true;

        // Duplicate ambiguity
        if (arr[low] == arr[mid] &&
            arr[mid] == arr[high]) {

            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {

            if (arr[low] <= target &&
                target < arr[mid]) {

                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        // Right half is sorted
        else {

            if (arr[mid] < target &&
                target <= arr[high]) {

                low = mid + 1;
            }
            else {

                high = mid - 1;
            }
        }
    }

    return false;
}

int main() {

    vector<int> nums = {2,5,6,0,0,1,2};

    int target = 0;

    if (searchInRotated(nums, target))
        cout << "Target Found";
    else
        cout << "Target Not Found";

    return 0;
}
