#include<bits/stdc++.h>
using namespace std;


void sumOfSubSet(int sum, int idx, vector<int>& res, vector<int>& arr,int n){
    
    if(idx == n){
        res.push_back(sum);
        return ;
    }
    
   
    sumOfSubSet(sum+arr[idx], idx+1, res, arr, n);
    
  
    sumOfSubSet(sum, idx+1, res, arr, n);
}

int main(){
    vector<int> vec = {1,2,3};
    int n = vec.size();
  
    int sum =0;
    int idx =0;
  
  
    vector<int> res;
    
    sumOfSubSet(sum, idx, res, vec, n);
    
    sort  (res.begin(), res.end());
    for(auto it : res){
        cout<< it << " ";
    };
    return 0;
}
