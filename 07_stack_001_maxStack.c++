// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxStack{
public:
    stack<pair<int,int>> st;
    
    MaxStack(){
    
    }
    
    void push(int val){
        if(st.empty()) st.push({val,val});
        
        else st.push({val, max(val,st.top().second)});
    }
    
    int top(){
        return st.top().first;
    }
    
    void pop(){
        st.pop();
    }
    
    int getMax(){
        return st.top().second;
    }
    
};





int main() {

    MaxStack obj;

    obj.push(5);
    obj.push(9);
    obj.push(2);
    obj.push(1);

    cout << "Top : " << obj.top() << endl;
    cout << "Max : " << obj.getMax() << endl;

    obj.pop();

    cout << "After Pop\n";

    cout << "Top : " << obj.top() << endl;
    cout << "Max : " << obj.getMax() << endl;

    cout << "\nStack Contents:\n";

    stack<pair<int,int>> temp = obj.st;

    while(!temp.empty()){
        cout << "Value = " << temp.top().first
             << ", Max = " << temp.top().second << endl;
        temp.pop();
    }

    return 0;
}
