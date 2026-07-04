// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int buySellStocks(vector<int>& arr) {

    int buyPrice = arr[0];
    int prevProfit = 0;

    for(int i = 1; i < arr.size(); i++) {

        // Profit if sold today
        int profit = arr[i] - buyPrice;

        // Update maximum profit
        if(profit > prevProfit)
            prevProfit = profit;

        // Update buying price if today's price is cheaper
        if(arr[i] < buyPrice)
            buyPrice = arr[i];
    }

    return prevProfit;
}
int main() {
    
    vector<int> arr = {5,29,100,25};
    int k = buySellStocks(arr);

    cout<< k;

    return 0;
}
