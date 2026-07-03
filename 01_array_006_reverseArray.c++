// reverse(arr.begin(),arr.end());
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {

    vector<int> arr= {1,2,3,4,5};
    
    int start =0;
    int end = arr.size()-1;
    int temp;
    
    while(end>start){
        temp = arr[start];
        arr[start] =arr[end];
        arr[end] =temp;
        
        start++;
        end--;
    }
    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     vector<int> arr = {1,2,3,4,5};

//     int start = 0;
//     int end = arr.size() - 1;

//     while(start < end) {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;

//         start++;
//         end--;
//     }

//     for(int i = 0; i < arr.size(); i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
