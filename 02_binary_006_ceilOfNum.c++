// Ceil of a Number (Smallest Element ≥ Target)
// ceil = lowerBound

// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Returns the smallest element >= target.
// Returns -1 if no such element exists.
int ceilOfNum(vector<int>& arr, int num) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    int ceilAns = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] >= num) {
            ceilAns = arr[mid];       // Current best ceil
            high = mid - 1;           // Search for a smaller valid ceil
        }
        else {
            low = mid + 1;
        }
    }

    return ceilAns;
}

int main() {

    vector<int> arr = {10, 30, 40, 50, 70, 100};

    int target = 20;

    cout << "Target : " << target << endl;
    cout << "Ceil   : " << ceilOfNum(arr, target);

    return 0;
}
