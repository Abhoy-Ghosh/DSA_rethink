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

Node* sumOf2LL(Node* head1,Node* head2){
    Node* h1 = head1;
    Node* h2 = head2;
    int carry = 0;
    
    Node* dummy = new Node(0,nullptr);
    Node* temp = dummy;
    
    while(h1 || h2 || carry){
        // edge case: if only carry exist after the whole traversal then it works also
        int sum  =  carry;
        
        // if  list1 does not exhaust then add the data from list1
        if(h1) {
            sum += h1->data;
            h1 = h1->next;
        }
        
        // if list2 does not exhaust then add  the data from list2
        if(h2) {
            sum += h2->data;
            h2 = h2->next;
        }
        
        // num is the digit at one
        int num  = sum%10;
        // carry is the digit at ten
        carry = sum/10;
        
        Node* newNode = new Node(num);
        temp->next = newNode;
        temp = temp->next;
    }
    // actual head is the dummy's next node
    return dummy->next;
}

int main() {
    vector<int> vec1 = {1,2,5,3,8};
    Node* head1 = createLL(vec1);
    printLL(head1);
    
    vector<int> vec2 = {2,3,7,5};
    Node* head2 = createLL(vec2);
    printLL(head2);
    
    Node* newHead = sumOf2LL(head1,head2);
    printLL(newHead);
    return 0;
}
