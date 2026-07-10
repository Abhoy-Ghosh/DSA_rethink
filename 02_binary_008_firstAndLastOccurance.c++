
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> firstAndLastOccurance(vector<int>& arr, int num){
    int n = arr.size();
    int first_lb = -1;
    int last_ub = -1;
    
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid = low+((high- low)/2);
        
        if(arr[mid] >= num){
            first_lb = mid;
            high= mid-1;
        }else low = mid+1;
        
    }
    // if the element does not exist there is no lower bound exist 
    // so check this edge case : element not in array
    // if no lower bound there is no need to check upper bound 
    // that cut the time from O(2log n) to O(log n)
    
    if(arr[first_lb] != num && first_lb == -1){
        cout << "ele not found" << endl;
        return {first_lb, last_ub};
    }
    
    low = 0;
    high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(arr[mid] > num){
            last_ub = mid;
            high = mid-1;
        }else low =mid+1;
    }
    
    return {first_lb,last_ub-1};
    
}

int main() {
    
    vector<int> vec = {1,2,3,3,3,4,4,4,4,5,6,7};
    pair<int,int> ans = firstAndLastOccurance(vec,5);
    cout<< "first occurance: " <<ans.first << endl;
    cout<< "last occurance: " <<  ans.second;
    return 0;
}
