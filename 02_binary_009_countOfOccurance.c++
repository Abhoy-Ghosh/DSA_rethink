// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int countOfOccurance(vector<int>& arr, int num){
    int n = arr.size();
    int first_lb = -1;
    int last_ub = n; // always upper bound set at n so that it will give correct result if there is no upper bound
    
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
    
    if(first_lb == -1 || arr[first_lb] != num){
        cout << "ele not found" << endl;
        return 0;
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
    
    return last_ub - first_lb;
    
}

int main() {
    
    vector<int> vec = {1,2,3,3,3,4,4,4,4,5,6,7,9,9};
    int target;
    cout << "target = ";
    cin >> target;
    int numberOfOccurance = countOfOccurance(vec,target);
    cout << "number of occurance of "<< target<< " in the array : " << numberOfOccurance;
    return 0;
}
