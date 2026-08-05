// for each element (right to left)

// 1. Pop unwanted elements.
// 2. Compute the answer.
// 3. Push the current element.
// 4. Move to the next index.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterEle(vector<int> arr){
    int n = arr.size();
    stack<int> st;
     vector<int> nge(n,-1);
    
    for(int i = n-1; i >=0; i--){
        while(!st.empty() && st.top()<= arr[i]){
            st.pop();
        }
        
        if(st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();
            
        st.push(arr[i]);
    }
    
    return nge;
}


int main(){
    vector<int> arr = {1,3,-3,4,0};
    vector<int> ans = nextGreaterEle(arr);
    for(auto it : ans){
        cout <<it << " ";
    }
    return 0;
}
