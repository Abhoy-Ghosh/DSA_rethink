class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        stack<int> st;
        vector<int> nge;
        unordered_map<int,int> hashNGE;
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty()){
                hashNGE[nums2[i]] =-1;
            }
            else hashNGE[nums2[i]] = st.top();

            st.push(nums2[i]);
        }


        for(int j = 0; j < m; j++){
            if(hashNGE.find(nums1[j]) != hashNGE.end()){
                nge.push_back(hashNGE[nums1[j]]);
            }
        }
        return nge;
    }
};


