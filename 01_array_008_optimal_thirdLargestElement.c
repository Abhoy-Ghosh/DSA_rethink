// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int find3rd(vector<int> arr){
    int largest = arr[0];
    int slargest= INT_MIN;
    int tlargest = INT_MIN;
    int n = arr.size();
    for (int i = 1; i< n; i++){
        if(largest<arr[i]){
            tlargest = slargest;
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > slargest && arr[i]< largest){
            tlargest = slargest;
            slargest = arr[i];
        }
        else if(arr[i] > tlargest && arr[i]< slargest){
            tlargest = arr[i];
            }
   }
       return tlargest; 
}
int main() {
    vector<int> nums = {1,57,7,58,2,7,66,7,8,90};
    int slargest = find3rd(nums);
    cout <<slargest;
    return 0;
}
