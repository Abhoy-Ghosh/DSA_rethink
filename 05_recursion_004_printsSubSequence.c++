#include<bits/stdc++.h>
using namespace std;

void printsSubSequence(int idx,vector<int>& ds,vector<int>& arr,int n){
    
   if(idx == n){
        if(ds.size() == 0) cout << "{}";
        
        for(auto it : ds){
        cout<< it << " ";
        }
        cout << endl;
    return;
   }
    ds.push_back(arr[idx]);
    printsSubSequence(idx+1, ds, arr, n);

    ds.pop_back();
    printsSubSequence(idx+1, ds, arr, n);
}

int main(){
    vector<int> vec = {1,2,3,1,1};
    int n = vec.size();
    int idx =0;
    vector<int> ds;
    
    int targetSum = 3;
    int s  = 0;
    
    printsSubSequence(idx,ds, vec, n);
    
    return 0;
}

