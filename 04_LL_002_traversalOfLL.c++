#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public: 
    Node(int data1, Node* next1){
        data =  data1;
        next = next1;
    }
    
    public: 
    Node(int data1){
        data = data1;
        next  = nullptr;
    }
};

Node* ArrToLL(vector<int>& data){
    
    Node* head = new Node(data[0]);
    Node* prev = head;
    
    for(int i = 1;i < data.size(); i++){
        Node* curr = new Node(data[i]) ;// curr is temporary constructor node
        prev->next = curr;
        prev = prev->next; // prev = curr
    }
   
    return head;
}

int main(){
     
    vector<int> data = {7,5,6,7,2};
    
    int n = data.size();
    
    Node* head= ArrToLL(data);
    Node* temp =head;
    
    // for(int i  = 0; i < n ; i++){
    //     if(head == NULL) return -1;
    //     else{
    //         cout<<temp->data << "-" << temp->next <<endl;
    //         temp = temp->next;
    //     }
    // }
    
    while(temp != nullptr){
        cout<< temp-> data << " ";
        temp = temp -> next;
    }
    
    return 0;
}
