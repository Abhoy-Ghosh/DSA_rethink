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
    
    Node* temp = head;
    
    Node* zero = new Node(-1);
    Node* zeroHead = zero;
    
    Node* one = new Node(-1);
    Node* oneHead = one;
    
    Node* two = new Node(-1);
    Node* twoHead = two;
    
    while(temp){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    Node* newHead = (zeroHead->next) ? zeroHead->next : (oneHead->next)? oneHead->next : twoHead->next;;
    
    zero->next = (oneHead->next)? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return newHead;
}

int main() {
    vector<int> vec = {1,2,1,0,2,2,0,1,0};
    Node* head  = createLL(vec);
    printLL(head);
    Node* newHead = sort012LL(head);
    printLL(newHead);
    return 0;
}
