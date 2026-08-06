#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// ----------------------------------------------------
// Previous Smaller or Equal Element (PSEE)
// ----------------------------------------------------
// For every index, find the nearest index on the left
// whose value is <= current value.
//
// Steps:
// 1. Pop all greater elements.
// 2. Current stack top becomes answer.
// 3. If stack empty, answer = -1.
// 4. Push current index.
//
vector<int> pseeIdx(vector<int>& arr){

    int n = arr.size();

    stack<int> st;
    vector<int> psee(n);

    for(int i = 0; i < n; i++){

        // Step 1 : Pop unwanted elements
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        // Step 2 : Compute answer
        if(st.empty())
            psee[i] = -1;          // imaginary index before array
        else
            psee[i] = st.top();

        // Step 3 : Push current index
        st.push(i);
    }

    return psee;
}

// ----------------------------------------------------
// Next Smaller Element (NSE)
// ----------------------------------------------------
// For every index, find the nearest index on the right
// whose value is < current value.
//
// We use >= while popping to correctly handle duplicates.
//
// Steps:
// 1. Pop all greater or equal elements.
// 2. Current stack top becomes answer.
// 3. If stack empty, answer = n.
// 4. Push current index.
//
vector<int> nseIdx(vector<int>& arr){

    int n = arr.size();

    stack<int> st;
    vector<int> nse(n);

    for(int i = n - 1; i >= 0; i--){

        // Step 1 : Pop unwanted elements
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        // Step 2 : Compute answer
        if(st.empty())
            nse[i] = n;            // imaginary index after array
        else
            nse[i] = st.top();

        // Step 3 : Push current index
        st.push(i);
    }

    return nse;
}

// ----------------------------------------------------
// Contribution Technique
//
// Instead of finding the minimum of every subarray,
// calculate how much each element contributes.
//
// Contribution =
// value × (number of choices on left) × (number of choices on right)
//
// left choices
// = distance from previous smaller/equal element
//
// right choices
// = distance to next smaller element
// ----------------------------------------------------
int sumOfSubarrayMinimums(vector<int> arr){

    vector<int> psee = pseeIdx(arr);
    vector<int> nse = nseIdx(arr);

    long long sum = 0;

    int n = arr.size();

    for(int i = 0; i < n; i++){

        // Number of choices on left
        long long left = i - psee[i];

        // Number of choices on right
        long long right = nse[i] - i;

        // Total contribution of current element
        long long contribution = left * right * arr[i];

        sum = (sum + contribution) % MOD;
    }

    return (int)sum;
}

int main(){

    vector<int> arr = {3,1,4,5};

    cout << "Array : ";

    for(int x : arr)
        cout << x << " ";

    cout << "\n";

    vector<int> p = pseeIdx(arr);

    cout << "PSEE : ";

    for(int x : p)
        cout << x << " ";

    cout << "\n";

    vector<int> n = nseIdx(arr);

    cout << "NSE  : ";

    for(int x : n)
        cout << x << " ";

    cout << "\n";

    cout << "Sum of Subarray Minimums = "
         << sumOfSubarrayMinimums(arr);

    return 0;
}
