
// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// aaabbcdd k =3

int longestSubstrWithKDistinctchar(string s, int k){
    int n = s.size();
    int l = 0, r = 0; 
    vector<int> freq(26,0);
    int len = 0, maxLen = 0;
    int uniq = 0;
    while(r<n){
        if(freq[s[r] -'a'] == 0)  uniq++;
        
        // if(freq[s[r]-'a'] >= 0){
            freq[s[r]-'a']++;
        // }
        if(uniq>k){
            freq[s[l]-'a']--;
            if(freq[s[l]-'a'] == 0){
                uniq--;
            }
            l++;
        }
        if(uniq <= k){
            len = r-l+1;
            maxLen = max(maxLen,len);
            r++;
        }
    }
    return maxLen;
}
int main() {
    string str = "aaabaabccbcccdd";
    int k = 3;
 int ans = longestSubstrWithKDistinctchar(str, k);
 
cout<<ans;
    return 0;
}
