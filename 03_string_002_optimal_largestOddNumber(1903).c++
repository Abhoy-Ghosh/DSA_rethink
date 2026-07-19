#include<bits/stdc++.h>
using namespace std;

string largestOddInString(string s){
  
  for(int i = s.size()-1; i >= 0; i--){
      int lastDigit = s[i] - '0';
      if(lastDigit % 2 != 0){
          return s.substr(0,i+1);
      }
  }
  return "";
}

int main(){
    
    string maxOdd = largestOddInString("44444754162222222222222222222222598456359789467");
    cout << maxOdd ;
    return 0;
}
