class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int slargest= -1; //INT_MIN if there is negative in the list
        int largest = nums[0];
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if( nums[i] > largest){
            slargest = largest;
            largest = nums[i];
            }
            else if(nums[i]>slargest && nums[i]!=largest){
                slargest = nums[i];
            }

    }
    return slargest;
    }
};
