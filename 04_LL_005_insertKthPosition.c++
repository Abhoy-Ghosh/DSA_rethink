
// Online C++ compiler to run C++ program online
#include <iostream>
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


Node* insertKthPosition(Node* head, int num, int pos){
    
    if(pos == 0) return head;
    
    Node* newNode = new Node(num);
    Node* prev  = head;
    int currPos = 1;
    
    // insert at head if the LL is empty
    if(head == nullptr) return newNode;
    
    // insert at pos 1 or head
    if(pos == 1){
        newNode->next = head;
        return newNode;
    }
    
    while(prev != nullptr && currPos < pos-1){ // break when pos given 5 it reaches 3 and 4th node is the node operation out of loop
    prev  = prev->next;
    currPos++;
    }
    
    if(prev == nullptr) 
    {cout<<"invalid pos"<< endl;
    delete newNode;
    return head;}
    
    newNode->next = prev->next;
    prev->next = newNode;
    
    
 return head;
}

int main() {
   
   vector<int> vec = {2,3,45,13,5};
   Node* head = createLL(vec);
   printLL(head);
   
   Node* newHead = insertPosition(head,4,0);
   printLL(newHead);
   return 0;
}












