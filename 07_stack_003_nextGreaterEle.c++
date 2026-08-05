

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterEle(vector<int> arr){
    int n = arr.size();
    
     vector<int> ans(n,-1);
        
    for(int i = 0; i < n; i++){
        for( int j =  i+1; j< n; j++){
            if(arr[i] < arr[j]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    
    return ans;
}


int main(){
    vector<int> arr = {1,3,-3,2,4,0};
    vector<int> ans = nextGreaterEle(arr);
    for(auto it : ans){
        cout <<it << " ";
    }
    return 0;
}
