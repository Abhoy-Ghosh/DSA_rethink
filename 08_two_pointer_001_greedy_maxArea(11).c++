

// # 🌊 Container With Most Water (LeetCode 11) | Greedy | Two Pointers | Visual Dry Run | C++

// # Intuition

// The amount of water a container can hold depends on:

// * The **shorter** of the two heights.
// * The **distance** between them.

// For two lines at indices `i` and `j`,

// ```text
// Area = min(height[i], height[j]) × (j - i)
// ```

// A brute-force solution checks every pair of lines, resulting in **O(n²)** time.

// Instead, we can use two pointers.

// Initially, the width is maximum because the pointers are at the two ends of the array.

// The key question is:

// > **Which pointer should we move?**

// Since the area is limited by the **shorter line**, moving the taller line cannot increase the height of the container while the width definitely decreases.

// Therefore, we always move the pointer pointing to the **shorter line**, hoping to find a taller line that increases the minimum height.

// ---

// # Approach

// 1. Place one pointer at the beginning (`l`) and one at the end (`r`).

// 2. Compute the current area.

// 3. Update the maximum area.

// 4. Move the pointer having the smaller height:

//    * If `height[l] <= height[r]`, move `l`.
//    * Otherwise, move `r`.

// 5. Continue until both pointers meet.

// ---

// # Visual Explanation

// Example

// ```text
// height = [1,8,6,2,5,4,8,3,7]
// ```

// Initial

// ```text
// Index : 0                     8
// Height: 1                     7

// Width = 8

// Area = min(1,7) × 8 = 8
// ```

// Move the shorter line (`1`).

// ```text
//       l                     r
//       8                     7

// Width = 7

// Area = min(8,7) × 7 = 49
// ```

// Maximum area becomes

// ```text
// 49
// ```

// Continue shrinking the window until both pointers meet.

// ---

// # Dry Run

// | Left | Right | Heights | Width | Area | Max Area |
// | ---: | ----: | ------: | ----: | ---: | -------: |
// |    0 |     8 |     1,7 |     8 |    8 |        8 |
// |    1 |     8 |     8,7 |     7 |   49 |       49 |
// |    1 |     7 |     8,3 |     6 |   18 |       49 |
// |    1 |     6 |     8,8 |     5 |   40 |       49 |
// |    2 |     6 |     6,8 |     4 |   24 |       49 |
// |    3 |     6 |     2,8 |     3 |    6 |       49 |
// |    4 |     6 |     5,8 |     2 |   10 |       49 |
// |    5 |     6 |     4,8 |     1 |    4 |       49 |

// Return

// ```text
// 49
// ```

// ---

// # Why Greedy Works?

// Suppose we have:

// ```text
// Left Height  = 4
// Right Height = 9
// ```

// Current area is determined by:

// ```text
// min(4,9) = 4
// ```

// If we move the taller line (`9`):

// * The width decreases.
// * The limiting height (`4`) remains the same.

// So the area can never increase.

// The only possibility of finding a larger area is to move the **shorter line**, hoping to replace it with a taller one while sacrificing some width.

// Therefore, moving the shorter pointer is always the optimal greedy choice.

// ---

// # Complexity

// * **Time Complexity:** **O(n)**

//   Each pointer moves at most `n` times.

// * **Space Complexity:** **O(1)**

//   Only a few variables are used.

// ---

// # Code

// ```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int maxi = 0;

        while (l < r) {

            int curr = min(height[l], height[r]) * (r - l);

            maxi = max(maxi, curr);

            if (height[l] <= height[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxi;
    }
};
// ```

// ---

// # Key Greedy Idea

// > **The area is always limited by the shorter line. Moving the taller line only decreases the width without increasing the limiting height. Therefore, always move the pointer pointing to the shorter line, as it is the only move that can potentially increase the maximum area.**
