class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ele;
       int count = 0;
       int n = nums.size();
    //   MOORE's voting algorithm

       for (int i = 0 ; i < n; i++){
        if(count == 0){
            ele = nums[i];
            count++;
        }
        else if(nums[i] == ele){
            count++;
        }
        else{
            count--;
        }
       }
    //    return ele;
    
    //  need to check it occurs >n/2 or not
    int countEle =0;
    int majorityEle;
    for (int i = 0; i< n; i++){
        if (nums[i] == ele) countEle++;
    }   
    if (countEle > n/2) {
     majorityEle=  ele;
    }
    return majorityEle;
    }
};
