// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

double avgWaitSJF(vector<int> arr){
    int n = arr.size();
    int startTime =0;
    int endTime = 0;
    int waiting  = 0;
    // vector<int>  wait;
    sort(arr.begin(),arr.end());
    
    for(int i = 0; i< n; i++){
        startTime = endTime;
        waiting += startTime;
        // wait.push_back(waiting);
        endTime = startTime + arr[i];
    }
    
    return (double)(waiting/n);
    
}

int main(){
    vector<int> jobs = {3,1,4,2,5};
    int ans  = avgWaitSJF(jobs);
    cout<< ans;
    return 0;
}
