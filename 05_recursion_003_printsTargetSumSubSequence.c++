

#include<bits/stdc++.h>
using namespace std;

void printsTargetSumSubSequence(int idx,vector<int>& ds,int s,vector<int>& arr,int n, int targetSum){
    
   if(idx == n){
    if(s == targetSum){
        if(ds.size() == 0) cout << "{}";
        
        for(auto it : ds){
        cout<< it << " ";
        }
        cout << endl;
    }
    return;
   }
    ds.push_back(arr[idx]);
    // printsSubSequence(idx+1, ds, arr, n);
    s += arr[idx];
    printsSubSequence(idx+1,ds, s, arr, n, targetSum) ;
    
    s-= arr[idx];
    ds.pop_back();
    printsSubSequence(idx+1,ds, s, arr, n, targetSum) ;
    // printsSubSequence(idx+1, ds, arr, n);
}

int main(){
    vector<int> vec = {1,2,3};
    int n = vec.size();
    int idx =0;
    vector<int> ds;
    
    int targetSum = 3;
    int s  = 0;
    
    printsSubSequence(idx,ds, s, vec, n, targetSum);
    
    return 0;
}

