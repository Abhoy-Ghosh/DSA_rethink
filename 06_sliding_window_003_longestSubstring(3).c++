
#include<bits/stdc++.h>
using namespace std;

string longestSubstring(string s){

    int n =  s.size();
    string ans = "";
    int maxLen = 0;
    int len = 0;
    if(s.empty()) return 0;

    int l = 0; 
    int r = 0;
    int start = 0;
    
    vector<int> hash(256,-1);

    while(r<n){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                start = l;
                l = hash[s[r]]+1;
        }
     }
        hash[s[r]] = r;
        len = r-l+1;
        maxLen = max(len,maxLen);

        r++;
    }
    ans = s.substr(l,maxLen);
    return ans;
}

int main(){
    string s = "cbbc";

    cout << longestSubstring(s);
    return 0;
}
