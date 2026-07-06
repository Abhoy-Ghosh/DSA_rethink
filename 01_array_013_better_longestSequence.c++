
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int longestSequence(vector<int> arr){
    int currentSequence = 0;
    int longestSequence = 0;
    int lastVisitedSmaller = INT_MIN;
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i <arr.size(); i++){
        if(lastVisitedSmaller == arr[i]-1){
            currentSequence++;
            lastVisitedSmaller = arr[i];
            longestSequence = max(currentSequence, longestSequence);
        }
        else if(arr[i] != lastVisitedSmaller){
            lastVisitedSmaller = arr[i];
            currentSequence = 1;
        }
    }
    return longestSequence;
}

int main(){

    vector<int> nums = {10,22,12,13,0,7,14,6,0,8,9};
    
    int ans = longestSequence(nums);

    cout << ans;

    return 0;
}
