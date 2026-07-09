// Floor of a Number (Largest Element ≤ Target)

// | Problem     | Condition            | Store Answer        | Move             |
// | ----------- | -------------------- | ------------------- | ---------------- |
// | Lower Bound | `arr[mid] >= target` | `mid` or `arr[mid]` | `high = mid - 1` |
// | Upper Bound | `arr[mid] > target`  | `mid` or `arr[mid]` | `high = mid - 1` |
// | Floor       | `arr[mid] <= target` | `arr[mid]`          | `low = mid + 1`  |
// | Ceil        | `arr[mid] >= target` | `arr[mid]`          | `high = mid - 1` |



#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Returns the largest element <= target.
// Returns -1 if no such element exists.
int floorOfNum(vector<int>& arr, int num) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int floorAns = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] <= num) {
            floorAns = arr[mid];      // Current best floor
            low = mid + 1;            // Search for a larger valid floor
        }
        else {
            high = mid - 1;
        }
    }

    return floorAns;
}

int main() {

    vector<int> arr = {10, 30, 40, 50, 70, 100};

    int target = 20;

    cout << "Target : " << target << endl;
    cout << "Floor  : " << floorOfNum(arr, target);

    return 0;
}
