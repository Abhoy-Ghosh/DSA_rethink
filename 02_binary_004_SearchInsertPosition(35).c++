// 35. Search Insert Position

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2

  
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> insertInCorrectPlace(vector<int>& arr, int num) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    // Default insertion position is at the end
    int ans = n;

    // Finding the Upper Bound
    // Upper Bound = First element strictly greater than num
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] > num) {
            ans = mid;          // Possible insertion position
            high = mid - 1;     // Search further left
        }
        else {
            low = mid + 1;      // Search right
        }
    }

    // Increase vector size by one to make room
    arr.push_back(0);

    // Shift all elements one position to the right
    // Start from the last original element
    for (int i = n; i > ans; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[ans] = num;

    return arr;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5,5, 7};

    insertInCorrectPlace(arr, 6);

    cout << "Array after insertion:\n";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    int pos = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
    arr.insert(arr.begin() + pos, num);
    return 0;
}
