class Solution{	
	public:
		bool isSorted(vector<int>& nums){
            // sorted in non-decreasing order
			for(int i = 1; i < nums.size(); i++){
                if(nums[i]>=nums[i-1]){

                }
                else{
                    return false;
                }
            }
            return true;
		}
};
