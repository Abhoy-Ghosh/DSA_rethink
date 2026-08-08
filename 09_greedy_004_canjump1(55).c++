
// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool canjump1(vector<int> arr){
    int n = arr.size();
    
    int maxDist = 0;
    
    for(int i = 0; i < n; i++){
        
        if(i > maxDist){
            return false; 
        }
        
        if(maxDist >= i){
            maxDist = max(maxDist, i+arr[i]);
        }
      
    }

    return true;
}

int main(){
    vector<int> jumps= {3,2,1,0,5};
    bool ans  = canjump1(jumps);
    cout<< ans;
    return 0;
}
