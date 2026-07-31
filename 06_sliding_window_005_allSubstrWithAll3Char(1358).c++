
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int allSubstrWithAll3Char(string s){
    int n = s.size();
    int l =0, r =0;
    int counter = 0;
    int final =0;
    map<char,int> mpp;
    
    while(r<n){

        mpp[s[r]]++;
    
        while(mpp.size()==3){
            counter = n-r;
            final = final+counter;
            counter =0;
            
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            
            l++;
        }
        r++;
    }
    return final;
}
int main() {
    
    string str = "aabcabc";
    int ans = allSubstrWithAll3Char(str);
    cout<<ans;
    return 0;
}
