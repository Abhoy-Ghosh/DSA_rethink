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
    temp->next = head;
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


int lengthOfLoopLL(Node* head){
    if(!head) return 0;
    
    Node* temp =  head;
    unordered_map<Node*,int> mpp;
    int visited =0;
    
    while(temp){
        if(mpp.find(temp) != mpp.end()){
            int firstVisit =mpp[temp];
            return visited-firstVisit;
        }
        mpp[temp] = visited;
        visited++;
        temp= temp->next;
         
    }
    return 0;
}





int main() {
    vector<int> vec = {1,2,1,0,2,2,0,1,0};
    Node* head  = createLL(vec);
    // printLL(head);
    int len =lengthOfLoopLL(head);
    cout << len;
    return 0;
}
