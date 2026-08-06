

// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int mod  =  10e+7;
int sumOfSubarrayMinimums(vector<int> arr){
    int n= arr.size();
    int sum = 0;
    for(int i = 0; i <n ; i++){
        int mini = arr[i];
        for(int j = i; j<n; j++){
            mini =  min(mini, arr[j]);
            sum = (sum + mini)% mod ;
        }
    }
    return sum;
}
int main() {
    vector<int> arr = {3,1,2,4,2,4,1,4,1,7,5,2,5};
    int ans  = sumOfSubarrayMinimums(arr);
    cout<< ans;
    return 0;
}
