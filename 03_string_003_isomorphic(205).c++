#include<bits/stdc++.h>
using namespace std;

bool isomorphic(string s,string t){
    if(s.size() != t.size()) return false;
    
    vector<int> lastSeenInS(256);
    vector<int> lastSeenInT(256);
    
    for(int i = 0; i< s.size(); i++){
        if(lastSeenInS[s[i]] != lastSeenInT[t[i]]) return false;
        
        lastSeenInS[s[i]] = i+1;
        lastSeenInT[t[i]] = i+1;
    }
  for(int i = 0; i < 256; i++) {
    if(lastSeenInS[i] != 0 || lastSeenInT[i] != 0) {
        cout << "'" << char(i) << "' : "
             << lastSeenInS[i]
             << "    "
             << "'" << char(i) << "' : "
             << lastSeenInT[i]
             << endl;
    }
}
    return true;
}

int main(){

    string s = "abba";
    string t = "egeg";
    bool isIsomorphic = isomorphic(s,t);
    
    cout << isIsomorphic ;
    return 0;
}

// Current Pair

// (s[i], t[i])

//         │
//         ▼

// Have these two characters
// appeared before?

//         │
//         ▼

// YES
// │
// ▼

// Did they last appear
// at the same index?

//         │
//         ├── Yes → Continue
//         │
//         └── No → Return False

//         ▲
//         │

// NO

//         │
//         ▼

// Both should be new

// (lastS == 0 && lastT == 0)

//         │
//         ▼

// Store current index
