// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// {1,2,3,4,5,6,7}
        // 20
int findSqrt(int num){
  
    if(num ==0 || num == 1) return num;
    
    int low = 1;
    int high = num/2; // the search upper limit can not cross the num/2 
    // like num is 9 so we only need to check for (9/2) = 4 as 4^2 = 16 > 9 
    
    int ans = 0;
    
    if(num>0){
    while(low<=high){
        int mid = low +(high-low)/2;
        
        long long square = mid*mid;
        // if square of mid is equal or less than num then
        // ans = mid and cut search space of left
        if(square <= num){
            ans= mid;
            low = mid+1;
        }
        else high = mid-1;
        } 
    }
    return ans;
}

int main() {
   
  int num = 25;

  cout <<  findSqrt(num);
    return 0;
}
