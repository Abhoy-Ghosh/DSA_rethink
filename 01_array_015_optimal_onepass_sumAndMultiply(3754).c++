//3754. Concatenate Non-Zero Digits and Multiply by Sum I

// You are given an integer n.
// Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.
// Let sum be the sum of digits in x.
// Return an integer representing the value of x * sum.

// Example 1:
// Input: n = 10203004
// Output: 12340
// Explanation:
// The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
// The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
// Therefore, the answer is x * sum = 1234 * 10 = 12340.



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    // long long sumAndMultiply(int num) {
    //     int sum =0;
    //     int x = 0;
    //     int temp =0;
    //     int res = 0;
        
    //     while(num>0){
    //      res = num%10;
    //         if(res != 0){
    //         temp = temp * 10 + res;
    //         }  
    //     num = num / 10;
    //     }
        

    //     while(temp>0){
    //         res = temp%10;
    //         x = x*10 + res;
    //         sum = sum+ res;
            
            
    //         temp = temp/10;
            
    //     }
        
    //     return sum*x;
    // }


    long long sumAndMultiply(int num) {
        int sum =0;
        double x = 0;
        int res = 0;
        int  i =1;
        
        while(num > 0){
            res = num%10;
            if(res > 0){
                x = res*0.1 + x*0.1;
                i = i*10;
                sum = sum +res;
            }
            num = num/10;
        }
          x = x*i;
          
        return x*sum;
    }

int main(){
    int ans = sumAndMultiply(1225844);
    
    cout<< ans;
}
