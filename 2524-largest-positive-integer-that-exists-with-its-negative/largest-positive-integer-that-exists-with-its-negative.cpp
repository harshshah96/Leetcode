class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int> st;
        int res=INT_MIN;

        for(auto ele: nums){
            //positive
            if(ele > 0 && ele>res && st.find((-1)*ele)!=st.end())res=ele;
            else if(ele < 0 && (-1)*(ele)> res && st.find((-1)*(ele))!=st.end()) res= (-1)*ele;

            st.insert(ele);
        }

        if(res<0) return -1;
        return res;
    }
};