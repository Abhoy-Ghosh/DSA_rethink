

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSequence(vector<int> arr){
    int n = arr.size();

    if(n == 0) return 0;

    int longSeq =0;
    unordered_set<int> st;

    for(int i = 0; i< n; i++){
        st.insert(arr[i]);
    }
    
    int currSeq;
    for(int it: st){
        if(st.find(it-1) == st.end()){
            currSeq =1;
            while(st.find(it+1) != st.end()){
                it = it+1;
                currSeq++;
            }
        longSeq =max(longSeq,currSeq);
        }

    }
    return longSeq;
}

int main() {

    vector<vector<int>> tests = {

        {100,4,200,1,3,2},               // 4
        {0,3,7,2,5,8,4,6,0,1},           // 9
        {10,22,12,13,0,7,14,6,0,8,9},    // 5
        {1,2,0,1},                       // 3
        {9,1,4,7,3,-1,0,5,8,-1,6},       // 7
        {},                              // 0
        {1},                             // 1
        {5,5,5,5},                       // 1
        {1,2,3,4,5},                     // 5
        {10,30,20,40}                    // 1
    };

    for(int i = 0; i < tests.size(); i++){

        cout << "Test Case " << i + 1 << ": ";

        for(int x : tests[i])
            cout << x << " ";

        cout << endl;

        cout << "Longest Sequence = "
             << longestSequence(tests[i])
             << endl;

        cout << "------------------------\n";
    }

    return 0;
}
