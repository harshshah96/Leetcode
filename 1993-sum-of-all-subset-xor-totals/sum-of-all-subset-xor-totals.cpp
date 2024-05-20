class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int result=0;

        for(auto &it : nums){
            result |= it;
        }

        return result << (n-1);


        
    }
};