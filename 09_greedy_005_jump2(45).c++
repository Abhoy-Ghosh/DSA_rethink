
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int jump2(vector<int>& arr){
    int n = arr.size();
    int l = 0;
    int r  =0;
    int jumps = 0;
    while(r < n-1){
        int maxDist = 0;
        for(int i = l; i <= r; i++){
            maxDist = max(i+arr[i], maxDist);
        }
        l = r+1;
        r = maxDist;
        jumps++;
    }
    return jumps;
}

int main() {
    vector<int> vec = {4, 1, 1, 3, 1, 1, 1, 1};
    int ans = jump2(vec);
    cout << ans;

    return 0;
}
