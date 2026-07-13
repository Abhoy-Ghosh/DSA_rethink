#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// {2,3,5,11}

int largestElement(vector<int>& arr){
    int largest = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(largest <= arr[i]){
            largest = arr[i];
        }
    }
    return largest;
}


int totalHour(vector<int>& arr,int hourly){
    int totalHr = 0;
    for(int i = 0; i < arr.size(); i++){
        totalHr += ceil((double)arr[i]/hourly);
    }
    return totalHr;
}


int kokoEatingBananas(vector<int> arr, int maxTotalTime){
    int ans =0;
    
    int maxi = largestElement(arr);
    
    int low =1 ;
    int high = maxi;
    int totalTime = 0;
    
    while(low <= high){
        int mid = low+((high-low)/2);
        
        totalTime = totalHour(arr, mid);
        
        if(totalTime <= maxTotalTime){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    if(ans == 0) cout << " not possible in given time";
    return ans;
}

int main() {
    vector<int> arrOfPilesOfBananas = {2,5,11,1,2,20};
    
    int maxTotalTime = 5;
    
    cout << "Eating speed (bananas/hour) : " << kokoEatingBananas(arrOfPilesOfBananas,maxTotalTime)<<endl;
    cout<< "largest: " << largestElement(arrOfPilesOfBananas)<< endl;
    // cout << totalHour(arrOfSpillOfBananas,7);
    return 0;
}

// Binary Search × Check Function

// = O(log M) × O(N)

// = O(N log M)

// where

// N = number of piles
// M = maximum pile size

