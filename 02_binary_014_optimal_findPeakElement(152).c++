
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int>& arr){
    int n = arr.size();
    
    if(n == 0) return -1;
    if(n == 1) return 0;
    
    int low = 0;
    int high = n-1;
    
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    
    low = 1;
    high = n-2;
    
    while(low <= high){
        int mid = low+((high- low)/2);
        // mid is peak
        if(arr[mid] >arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }   
        // peak in left side 
        else if(arr[mid] >arr[mid-1]){
            low = mid+1;
        }
        // peak in right side
        else if(arr[mid] >arr[mid+1]){
            high= mid-1;
        }
        // peak in both side
        else if(arr[mid] < arr[mid+1] && arr[mid] < arr[mid-1]){
            low = mid+1; //or high = mid-1
        }   
    }
    return -1;
}

int main() {
    vector<int> vec ={1,25,5,8,9,14};
    
    int peakEleIdx = peakElement(vec);
    
    cout << "peak ele index: "<<peakEleIdx;

    return 0;
}
