#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* createLL(vector<int>& arr){
    if(arr.size()== 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode =  new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next ;
    }
    return head;
}


void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data << " ";
        temp =temp->next;
    }
    cout << endl;
}

Node* sort012LL(Node* head){
    if(!head) return nullptr;
    
   int c0=0;
   int c1=0;
   int c2=0;
   
   Node* temp = head;
   while(temp){
       if(temp->data==0) c0++;
       else if(temp->data ==1) c1++;
       else c2++;
       temp = temp->next;
   }
   temp = head;
  
   while(temp){
       if(c0){
           temp->data = 0;
           c0--;
       } 
       else if(c1){
           temp->data = 1;
           c1--;
       }
       else{
           temp->data = 2;
           c2--;
       }
       temp =temp->next;
   }
   return head;
}

int main() {
    vector<int> vec = {1,2,1,0,2,2,0,1};
    Node* head  = createLL(vec);
    printLL(head);
    Node* newHead = sort012LL(head);
    printLL(newHead);
    return 0;
}
