#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Find the index of the tallest bar (global maximum).
// This bar acts as a guaranteed boundary for both halves.
int idxOfLargestEle(vector<int>& arr){
    int l = arr[0];
    int idx = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > l){
            l = arr[i];
            idx = i;
        }
    }
    return idx;
}

// O(n) Time
// O(1) Extra Space
int trappingRainWater(vector<int>& arr){

    int n = arr.size();

    // The tallest bar splits the array into two independent halves.
    int largestEleIdx = idxOfLargestEle(arr);

    // l -> index of the tallest bar encountered so far from the left.
    // r -> current index being processed.
    int l = 0, r = 1;

    int sum = 0;

    // (Optional) Stores trapped water at each index.
    vector<int> trappedRainWater(n,0);

    // ====================================================
    // LEFT HALF
    // ====================================================
    //
    // Traverse from the beginning to the tallest bar.
    //
    // Since the tallest bar exists on the right,
    // every index on this side is guaranteed to have
    // a valid right boundary.
    //
    // Therefore, the amount of water depends ONLY on
    // the tallest bar seen so far from the LEFT.
    //
    // l always stores the index of that tallest bar.
    //
    while(r <= largestEleIdx){

        // Current left boundary is taller.
        // Water can be trapped.
        if(arr[l] > arr[r]){

            trappedRainWater[r] = arr[l] - arr[r];
            sum += trappedRainWater[r];
        }

        // Found a taller/equal bar.
        // Update the left boundary.
        else{
            l = r;
        }

        r++;
    }

    // ====================================================
    // RIGHT HALF
    // ====================================================
    //
    // Traverse from the end towards the tallest bar.
    //
    // Since the tallest bar exists on the LEFT,
    // every index on this side automatically has
    // a valid left boundary.
    //
    // Therefore, water depends ONLY on the tallest
    // bar seen so far from the RIGHT.
    //
    l = n - 2;
    r = n - 1;

    while(l > largestEleIdx){

        // Current right boundary is taller.
        if(arr[r] > arr[l]){

            trappedRainWater[l] = arr[r] - arr[l];
            sum += trappedRainWater[l];
        }

        // Found a taller/equal bar.
        // Update the right boundary.
        else{
            r = l;
        }

        l--;
    }

    return sum;
}

int main(){

    vector<int> arr = {4,2,0,3,2,5};

    cout << trappingRainWater(arr);

    return 0;
}
