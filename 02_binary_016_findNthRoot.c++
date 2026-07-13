
#include<bits/stdc++.h>
using namespace std;

int findNthRoot(int num, int nRoot){

    int ans = 0;

    if(num < 0){
        cout << "Imaginary Number";
        return -1;
    }

    if(num <= 1)
        return num;

    int low = 1;
    int high = num;

    while(low <= high){

        int mid = low + (high - low) / 2;

        long long x = 1;

        // Copy nRoot because we should not modify it
        int power = nRoot;

        while(power != 0){

            x *= mid;          // Compute mid^nRoot

            // Prevent overflow
            if(x > num)
                break;

            power--;
        }

        if(x == num)
            return mid;        // Exact nth root found

        if(x < num){

            ans = mid;         // Store floor nth root
            low = mid + 1;
        }
        else{

            high = mid - 1;
        }
    }

    return ans;                // Floor of nth root
}

int main(){

    int num = 27;
    int N = 3;

    cout << findNthRoot(num, N);

    return 0;
}


// ### Complexity

// * **Binary Search:** `O(log num)`
// * **Power Calculation per iteration:** `O(nRoot)`

// **Overall Time Complexity:** `O(nRoot × log(num))`

// **Space Complexity:** `O(1)`
