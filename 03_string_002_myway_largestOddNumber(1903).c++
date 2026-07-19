#include<bits/stdc++.h>
using namespace std;

long long int largestOddInString(string s){
    // generate all the numbers
    //  divide by 2
    // if divide update in ans
    //  maintain max ans 
    
    long long int maxi = -1;
    string num = "";

    
    for(auto c : s){
        num += c;
        long long int x= stoll(num);
        if(x%2 != 0){
            maxi = x;
        }
    }
    
    return maxi;
}

int main(){
    
   long long maxOdd = largestOddInString("5451176");
    cout << maxOdd ;
    return 0;
}
