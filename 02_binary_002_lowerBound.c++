#include <iostream>
#include <vector>
using namespace std;

// Returns the index of the first element >= target.
// Returns -1 if no such element exists.
int lowerBound(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    int index = lowerBound(arr, 3);

    if (index != -1) {
        cout << "Lower Bound Index : " << index << endl;
        cout << "Lower Bound Value : " << arr[index] << endl;
    } else {
        cout << "Lower Bound does not exist." << endl;
    }

    cout << "STL Lower Bound Index : "
         << lower_bound(arr.begin(), arr.end(), 3) - arr.begin();

    return 0;
}
