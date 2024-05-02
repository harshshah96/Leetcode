class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int> st;
        int res=INT_MIN;

        for(auto ele : nums){
            
            if(ele > 0 && ele > res && (st.find( (-1)*ele ) != st.end())){ //  positive
                res=ele;
            }else if(ele < 0 && abs(ele) > res && (st.find(abs(ele)) != st.end())){ //  Negative
                res= abs(ele);
            } 
            
            st.insert(ele);
        }

        if(res<0) return -1;
        return res;
    }
};