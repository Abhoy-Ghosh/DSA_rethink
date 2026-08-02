#include<bits/stdc++.h>
using namespace std;

05_recursion_006_numOfSubSequenceWithTargetSum.c++
int numOfSubSequenceWithTargetSum(int idx,vector<int> ds,int s,vector<int> arr,int n, int targetSum){
    
    if(idx == n){
        if(s == targetSum){
           return 1;
        }
        else return 0;
    }
    
    ds.push_back(arr[idx]);
    int left = numOfSubSequenceWithTargetSum(idx+1, ds, s+arr[idx], arr, n, targetSum);
    
    ds.pop_back();
    int right = numOfSubSequenceWithTargetSum(idx+1, ds, s, arr, n, targetSum);
    
    return left+right;
}

int main(){
    vector<int> vec = {1,2,3,0,1,1,2,1};
    int n = vec.size();
     int targetSum = 3;
     
    int idx =0;
    int s = 0;
    vector<int> ds;
 
    int numOfSubSeq = numOfSubSequenceWithTargetSum(idx, ds, s, vec, n, targetSum);
    cout << numOfSubSeq;
    return 0;
}
