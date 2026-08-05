// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxMinStack{
public:
    stack<vector<int>> st;
    
    MaxMinStack(){
    
    }
    
    void push(int val){
        if(st.empty()) st.push({val,val,val});
        
        else st.push({val, max(val,st.top()[1]), min(val,st.top()[2])});
    }
    
    int top(){
        return st.top()[0];
    }
    
    void pop(){
        st.pop();
    }
    
    int getMax(){
        return st.top()[1];
    }
    
    int getMin(){
        return st.top()[2];
    }
    
};





int main() {

    MaxMinStack obj;

    obj.push(5);
    obj.push(9);
    obj.push(-1);
    obj.push(2);
    obj.push(1);
    obj.push(10);

    cout << "Top : " << obj.top() << endl;
    cout << "Max : " << obj.getMax() << endl;
    cout << "Min : " << obj.getMin() << endl;

    obj.pop();

    cout << "After Pop\n";

    cout << "Top : " << obj.top() << endl;
    cout << "Max : " << obj.getMax() << endl;
    cout << "Min : " << obj.getMin() << endl;

    cout << "\nStack Contents:\n";

    stack<vector<int>> temp = obj.st;

    while(!temp.empty()){
        cout << "Value = " << temp.top()[0]
             << ", Max = " << temp.top()[1]
             << ", Min = " << temp.top()[2] << endl;;
        temp.pop();
    }

    return 0;
}
