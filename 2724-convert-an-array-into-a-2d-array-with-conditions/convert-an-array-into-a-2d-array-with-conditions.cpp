static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max_freq=INT_MIN;

        for(int ele : nums){
            mp[ele]++;
            max_freq = max(max_freq,mp[ele]);
        }

        vector<vector<int>> ans(max_freq);
        for(auto ele : mp){
            for(int i=0; i<ele.second; i++){
                ans[i].push_back(ele.first);
            }
        }

        return ans;
        
    }
};