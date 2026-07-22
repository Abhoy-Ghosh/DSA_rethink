// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// struct node{ //struct version
//     public:
//     int data;
//     node* next;
//     public:
//     node(int data1,node* next1){
//         data =data1;
//         next = next1;
//     }
// };

class Node{ //class version
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

int main() {
    vector<int> arr = {4,5,26,7,8};
    Node x = Node(arr[0],nullptr); // x is a object ..stores in stack
    cout << x.data << endl;
    cout << x.next << endl;
    
   Node* y = new Node(arr[0],nullptr); // y is pointer  to the new node ..memory in heap
   
    cout<< y << endl << y->data <<endl << y-> next<<endl;
    delete y; // need to release the memory manually
    cout << y->data;
    return 0;
}


// The two techniques are creating the same `node` object, but **one is on the stack and the other is on the heap**.

// ```cpp
// node x = node(arr[0], nullptr);
// ```

// and

// ```cpp
// node* y = new node(arr[0], nullptr);
// ```

// look similar, but they work differently.

// ---

// ## 1. Stack allocation

// ```cpp
// node x = node(arr[0], nullptr);
// ```

// ### What happens?

// 1. Memory is reserved on the **stack**.
// 2. The constructor is called.
// 3. `x` itself is the object.

// ```
// Stack
// +----------------+
// | x              |
// | data = 4       |
// | next = nullptr |
// +----------------+
// ```

// The constructor executes

// ```cpp
// node(int data1, node* next1){
//     data = data1;
//     next = next1;
// }
// ```

// so

// ```
// data = 4
// next = nullptr
// ```

// Now

// ```cpp
// cout << x.data;
// ```

// prints

// ```
// 4
// ```

// and

// ```cpp
// cout << x.next;
// ```

// prints

// ```
// 0
// ```

// (or `0x0` depending on the compiler).

// When `main()` finishes, **`x` is automatically destroyed** because it lives on the stack.

// ---

// ## 2. Heap allocation

// ```cpp
// node* y = new node(arr[0], nullptr);
// ```

// ### What happens?

// `new` does **two things**:

// ### Step 1

// Allocates memory on the **heap**.

// ```
// Heap

// +----------------+
// | ?              |
// | ?              |
// +----------------+
// ```

// ### Step 2

// Calls the constructor on that memory.

// ```
// Heap

// +----------------+
// | data = 4       |
// | next = nullptr |
// +----------------+
// ```

// ### Step 3

// Returns the address of that memory.

// Suppose the object is stored at

// ```
// 0x61ff20
// ```

// Then

// ```
// Stack

// +------------+
// | y          |
// | 0x61ff20   |
// +------------+

// Heap

// 0x61ff20
// +----------------+
// | data = 4       |
// | next = nullptr |
// +----------------+
// ```

// Notice

// `y` is **not** the node.

// `y` only stores the address of the node.

// Therefore

// ```cpp
// cout << y;
// ```

// prints something like

// ```
// 0x61ff20
// ```

// If you want the data,

// ```cpp
// cout << y->data;
// ```

// prints

// ```
// 4
// ```

// because

// ```cpp
// y->data
// ```

// means

// ```cpp
// (*y).data
// ```

// ---

// # Why `.` vs `->`?

// For

// ```cpp
// node x(...);
// ```

// `x` is an object.

// ```
// x
// ```

// So

// ```cpp
// x.data
// ```

// For

// ```cpp
// node* y;
// ```

// `y` is a pointer.

// ```
// y -----> node
// ```

// To access members,

// ```cpp
// (*y).data
// ```

// which is written as

// ```cpp
// y->data
// ```

// ---

// # Memory comparison

// ### Stack object

// ```
// Stack

// x
// +----------------+
// | data = 4       |
// | next = nullptr |
// +----------------+
// ```

// Access:

// ```cpp
// x.data
// x.next
// ```

// Automatically destroyed.

// ---

// ### Heap object

// ```
// Stack

// y
// +----------+
// | 0x1000   |
// +----------+

//         |
//         v

// Heap

// 0x1000
// +----------------+
// | data = 4       |
// | next = nullptr |
// +----------------+
// ```

// Access:

// ```cpp
// y->data
// y->next
// ```

// Must be manually destroyed:

// ```cpp
// delete y;
// ```

// Otherwise you leak memory.

// ---

// ## Why do we usually use `new` for linked lists?

// Suppose you write:

// ```cpp
// node first(1, nullptr);
// node second(2, nullptr);

// first.next = &second;
// ```

// This works only while both variables are alive. If they go out of scope (for example, a function returns), the pointers become invalid.

// With

// ```cpp
// node* first = new node(1, nullptr);
// node* second = new node(2, nullptr);

// first->next = second;
// ```

// both nodes stay alive until you explicitly `delete` them, which is why linked lists traditionally use dynamic allocation. (In modern C++, smart pointers such as `std::unique_ptr` are often preferred to avoid manual memory management.)
