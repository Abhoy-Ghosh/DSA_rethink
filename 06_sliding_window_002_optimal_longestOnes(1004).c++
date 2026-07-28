class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int  n = nums.size();
    int l=0, r=0;
    int zeroesCounter = 0;
    int currLen = 0;
    int maxLen = 0;
    while(r<n){
        if(nums[r] == 0) zeroesCounter++;

        while(zeroesCounter > k){
            if(nums[l] == 0) zeroesCounter--;
            l++;
        }

        if(zeroesCounter <= k){
            currLen = r-l+1;
            maxLen = max(currLen,maxLen);
            r++;
        }
    }
    return maxLen;
    }
};
