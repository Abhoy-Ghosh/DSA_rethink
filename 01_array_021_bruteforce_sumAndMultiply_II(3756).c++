
// 3756. Concatenate Non-Zero Digits and Multiply by Sum II

// You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].
// For each queries[i], extract the substring s[li..ri]. Then, perform the following:
// Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
// Let sum be the sum of digits in x. The answer is x * sum.
// Return an array of integers answer where answer[i] is the answer to the ith query.
// Since the answers may be very large, return them modulo 109 + 7.

// Example 1:
// Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
// Output: [12340, 4, 9]

// Explanation:

// s[0..7] = "10203004"
// x = 1234
// sum = 1 + 2 + 3 + 4 = 10
// Therefore, answer is 1234 * 10 = 12340.
// s[1..3] = "020"
// x = 2
// sum = 2
// Therefore, the answer is 2 * 2 = 4.
// s[4..6] = "300"
// x = 3
// sum = 3
// Therefore, the answer is 3 * 3 = 9.





#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
    
    vector<int> ans;
    
    // processing string to number 
    vector<int> num;
    
    for(char c: s){
        num.push_back(c-'0'); //char 0 is need to substract or it push the ascii value of each number ..like '1' -> 49, 
    }
    
    // processing the queries 
    int nrow = queries.size();
    
    for(int i = 0;i < nrow; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            
            int new_num= 0;
            int sum = 0;
            
                for(int idx= left; idx<=right; idx++){
                    if(num[idx] > 0){
                        new_num = new_num*10 + num[idx];
                        sum = sum+num[idx];
                    }
                }
            
            ans.push_back(sum * new_num);
    }
    
    return ans;
}

int main(){

    vector<vector<int>>queries = {{0,7},{1,3},{4,6}};
    
    vector<int> ans = sumAndMultiply("10203004",queries);
    
    int n = ans.size();   
        
    for(int i= 0; i< n; i++){
        cout<< ans[i]<< " ";
    }
    return 0;
    
    
}
