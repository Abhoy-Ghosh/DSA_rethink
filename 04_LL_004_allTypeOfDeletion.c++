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
};

Node* createLL(vector<int>& arr){
    
    Node* head = new Node(arr[0],nullptr);
    Node* prev = head;
    
    for(int i = 1; i < arr.size(); i++){
        Node* curr = new Node(arr[i],nullptr);
        prev->next = curr;
        prev = prev->next;
    }
    return head;
}

// // deletion of head
// Node* deleteHead(Node* head){
// if(head == NULL) return head;
//     Node* newHead = head->next;
//     delete head;
//     return newHead;
// }


// // delation of tail
// Node* deleteTail(Node* head){
//     if(!head) return head;
//     if(!head->next) {
//         free(head);
//         return nullptr;
//     }
    
//     Node* temp = head;
//     Node* prev = nullptr;
//     while(temp->next != nullptr){
//         prev = temp;
//         temp = temp->next;
//     }
//     //at this point temp->next = nullptr
//     // temp = 2
//     //prev->next = 5
//     prev->next = nullptr;
//     delete temp; //free(temp);
//     return head;
// }


// // deletion of kth element
// Node* deleteKthEle(Node* head,int k){
//     if(!head || !head->next) return nullptr;
    
//     Node* temp = head;
//     Node* prev = head;
//     int counter = 1;
    
//     while(temp){
//         if(counter == k){
//             prev->next= temp->next;
//             delete temp;
//             return head;
//         }
//         prev = temp;
//         temp = temp->next;
//         counter++;
//     }
//     return head;
    
// }


// deletion upon value
Node* deleteValue(Node* head,int val){
    if(head == nullptr) return nullptr;
    
    if(head->data == val){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
    Node* temp = head;
    Node* prev = nullptr;
    
    while(temp){
        if(temp->data == val){
            prev->next = temp->next;
            delete temp;
            // temp = prev->next // if want to delete all occurance of value
            return head; // if delete only first occurance
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    if(temp == nullptr) cout<< "not found value" <<endl;
    return head;
}
int main(){
    vector<int> vec ={1,2,3,4,2};
    Node* start  = createLL(vec);
    
    // Node* newStart = deleteHead(start);
    // Node* temp = newStart;
    
    Node* temp = start;
    // temp = deleteTail(temp);
    
    // temp = deleteKthEle(temp,1);
    
    temp = deleteValue(temp,2);
    int counter = 0;
    
    while(temp!=nullptr){
        cout<<temp->data << " ";
        temp = temp->next;
        counter++;
    }
    cout << endl << counter <<endl;

}
