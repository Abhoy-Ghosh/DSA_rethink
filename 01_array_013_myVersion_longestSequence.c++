// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSequence(vector<int> arr){

    // Find the largest element
    int largest = arr[0];

    for(int i = 0; i < arr.size(); i++){
        if(largest < arr[i]){
            largest = arr[i];
        }
    }

    // Hash array to mark the presence of elements
    vector<int> hash(largest + 1, 0);

    for(int i = 0; i < arr.size(); i++){
        hash[arr[i]] = 1;
    }

    int longestSeq = 0;
    int currSeq = 0;

    // Count consecutive 1's in the hash array
    for(int i = 0; i < hash.size(); i++){

        if(hash[i] == 1){
            currSeq++;
            longestSeq = max(longestSeq, currSeq);
        }
        else{
            currSeq = 0;
        }
    }

    return longestSeq;
}

int main(){

    vector<int> nums = {10,22,12,13,0,7,14,6,0,8,9};

    int ans = longestSequence(nums);

    cout << "Longest Consecutive Sequence Length = " << ans;

    return 0;
}

/*
Assumptions:
1. All elements are non-negative integers.
2. The maximum element is reasonably small.

Limitations:
1. Does not work for negative numbers.
2. Not suitable when the maximum element is very large
   (e.g., 10^9), as the hash array becomes too large.

Time Complexity:
O(n + maxElement)

Space Complexity:
O(maxElement)
*/
