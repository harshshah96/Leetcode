class Solution {
public:
        
    void helper(vector<int> & nums,vector <vector<int>> &v, int idx,vector<int> &ans){
        if(idx==nums.size()){
            v.push_back(ans);
            return;

        }
        helper(nums,v,idx+1,ans);
        ans.push_back(nums[idx]);
        helper(nums,v,idx+1, ans);
        ans.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        vector<int> ans;
        vector <vector<int>> v;
        helper(nums, v,0,ans);
        return v;
        
            
        
    }
};