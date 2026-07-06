.// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> leaderInArray(vector<int> nums){
    int leader = INT_MIN;
    vector<int> leaders;
    int n = nums.size();
    for(int i = n-1; i >=0; i--){
        if(nums[i] > leader){
            leader = nums[i];
            leaders.push_back(leader);
            
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}
int main(){

    vector<int> nums = {10,22,12,3,0,6,0,9};

    vector<int> ans = leaderInArray(nums);

    cout << "Leaders: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}
