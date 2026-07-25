// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fact(int num){
    if(num < 0) return -1;
    if(num<=1) return 1;
    
    int i= num;
    int factorial = i * fact(i-1);
    return factorial;
}
int main() {
   cout<< fact(10);

    return 0;
}
