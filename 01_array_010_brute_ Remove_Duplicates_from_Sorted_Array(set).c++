// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr){
    int n = arr.size();
    unordered_set<int> unique;
    int index = 0;
    
    for(int num : arr){
        if(unique.find(num) == unique.end()){
            unique.insert(num);
            arr[index] = num;
            index++;
        }
    }
    for(int i : unique){
        cout<< i << endl;
    }
    int i = 0;
    while(i < index){
        cout << arr[i] <<endl ;
        i++;
    }
    return index;
}
int main() {
    
    vector<int> arr = {1,1,2,2,3,4,4,5,5};
    int k = removeDuplicates(arr);
    for (int i = 0; i< k ;i++){
        cout << arr[i] << endl;
    }
    
    cout<< k;

    return 0;
}
