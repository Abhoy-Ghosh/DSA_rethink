// // return  arr[low];   low after traversal pointing to the ceil value    
// // return arr[high]; high also pointing the floor after traversal is this really ok 

// Excellent observation! Yes, this is true—but only if you handle the boundary cases correctly.

// After a standard binary search finishes:

// while (low <= high) {
//     ...
// }

// the loop ends when

// low = high + 1

// At that point:

// low points to the first element greater than or equal to the target (the ceil / lower bound position).
// high points to the last element less than or equal to the target (the floor).
// Example 1
// Array : 10 30 40 50 70 100
// Target = 20

// Final state:

//         low
//          ↓
// 10 30 40 50 70 100
//  ↑
// high
// high = 0 → 10  (Floor)
// low  = 1 → 30  (Ceil)

// So,

// floor = arr[high];
// ceil  = arr[low];

// ✅ Correct.



#include <iostream>
#include <vector>
using namespace std;

pair<int, int> floorAndCeil(vector<int>& arr, int target) {

    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // Target found
            return {arr[mid], arr[mid]};
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    int floor = (high >= 0) ? arr[high] : -1;
    int ceil  = (low < n) ? arr[low] : -1;

    return {floor, ceil};
}

int main() {

    vector<int> arr = {10, 30, 40, 50, 70, 100};

    auto ans = floorAndCeil(arr, 45);

    cout << "Floor : " << ans.first << endl;
    cout << "Ceil  : " << ans.second << endl;
}
