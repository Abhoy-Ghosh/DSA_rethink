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

Node* oddEvenLL(Node* head){
    if(!head) return nullptr;
    
    Node* odd = head;
    Node* even = head->next;
    
    Node* evenHead = even; //preserve the  even head
    
    while(even!=nullptr && even->next!=nullptr){
        // first condition break if the length is odd
        // second condition breakk if the length is even
        odd->next = even->next; //odd->next->next
        odd = odd->next;
       
        even->next = odd->next;
        even = even->next;
    }
    //final connection end of odd and start of even
     odd->next = evenHead;
    return head;
}

int main() {
    vector<int> vec = {1,2,5,6,7,9};
    Node* head  = createLL(vec);
    printLL(head);
    Node* newHead = oddEvenLL(head);
    printLL(newHead);
    return 0;
}
