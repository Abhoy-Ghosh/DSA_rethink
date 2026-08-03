
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// extra space 
// void printPermutation(vector<int>& ds, vector<int>& map, vector<int>& arr, vector<vector<int>>& ans , int n){
    
//     if(ds.size() == n){
//         ans.push_back(ds);
        
//         return ;
//     }
    
//     for(int i = 0; i < arr.size(); i++){
//         if(map[i] ==0){
//             ds.push_back(arr[i]);
//             map[i] = 1;
//             printPermutation(ds,map,arr,ans,n);
//             ds.pop_back();
//             map[i] = 0;
//         }
//     }
// }


void printPermutation2(int idx,vector<vector<int>>& ans, vector<int>& arr, int n){
    
    if(idx == n){
        ans.push_back(arr);
        return;
    }
    
    
    for(int i = idx; i < n; i++){
        swap(arr[idx],arr[i]);
        printPermutation2(idx+1,ans, arr, n);
        swap(arr[idx],arr[i]);
        
    }
}

int main(){
    vector<int> arr = { 1,2,3};
    int n = arr.size();
    vector<int> ds ;
    vector<int> map(n,0);
    vector<vector<int>> ans;
    
    //  printPermutation(ds,map,arr,ans,n);
     
     printPermutation2(0, ans, arr, n);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<< ans[i][j] << " ";
        }
     cout<< endl;
    }
    return 0;
}
