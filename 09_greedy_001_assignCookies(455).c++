
// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int assignCookies(vector<int>& cookies, vector<int>& child){
    int m = cookies.size();
    int n = child.size();
    int countCookies = 0;
    int countChild = 0;
    
    sort(cookies.begin(), cookies.end());
    sort(child.begin(), child.end());
    
    int i =0 , j =0;
    while(i < m && j < n){
        if(cookies[i] >= child[j]){
            countCookies+= cookies[i];
            countChild ++;
            j++;
        }
        i++;
    }
    return countChild;
}

int main (){
    vector<int> co = {2,5,1,4};
    vector<int> ch = {1,3,4};
    
    int ans = assignCookies(co,ch);
    cout<< ans;
}


// Greedy Idea

// Always give the smallest cookie that can satisfy the current least greedy child. This preserves larger cookies for greedier children later, maximizing the total number of satisfied children.
