class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {

          k = k % nums.size();
          
          if(k == 0) return;

          vector<int> temp(k);

            for(int i =0; i <nums.size(); i++){
                if(i < k){
                    temp[i] = nums[i];
                }
                else if(i >= k && i < nums.size()-k){
                    nums[i-k] = nums[i];
                }
                else{
                    nums[i-k] = nums[i];
                    nums[i]= temp[i - (nums.size() -k)];
                }
            }
    }
};
