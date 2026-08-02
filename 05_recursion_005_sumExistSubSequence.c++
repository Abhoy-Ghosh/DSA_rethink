#include<bits/stdc++.h>
using namespace std;

bool sumExistSubSequence(int idx,vector<int>& ds,int s,vector<int>& arr,int n, int targetSum){
    
   if(idx == n){
    return (s == targetSum);
   }
 
    //Take
    ds.push_back(arr[idx]);
    s += arr[idx];
    if(sumExistSubSequence(idx+1,ds, s, arr, n, targetSum))
        return true;
        
    // BackTrack
    s-= arr[idx];
    ds.pop_back();

    //Not Take  
    if(sumExistSubSequence(idx+1,ds, s, arr, n, targetSum)) 
        return true;
    
    return false;
}

int main(){
    vector<int> vec = {1,2,3,1};
    int n = vec.size();
    int idx =0;
    vector<int> ds;
    
    int targetSum = 9;
    int s  = 0;
    
    bool exist = sumExistSubSequence(idx,ds, s, vec, n, targetSum);
    cout << exist;
    return 0;
}


