#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseString(string S) {

    reverse(S.begin(), S.end());

    int count = 0;

    for(int c = 0; c <= S.size(); c++) {

        if(c < S.size() && S[c] != ' ') {
            count++;
        }
        else {
            
            reverse((S.begin() + c) - count, S.begin() + c);
            count = 0;
        }
    }

    return S;
}

int main() {

    string s = "the sky is blue";

    cout << reverseString(s);

    return 0;
}
