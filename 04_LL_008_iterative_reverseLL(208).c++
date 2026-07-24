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

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* nex = nullptr;
    if(head == nullptr) return nullptr;
    
    while(curr!=nullptr){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}

int main() {
    vector<int> vec = {1,2,5,6,7,9};
    Node* head  = createLL(vec);
    printLL(head);
    Node* newHead = reverseLL(head);
    printLL(newHead);
    return 0;
}
