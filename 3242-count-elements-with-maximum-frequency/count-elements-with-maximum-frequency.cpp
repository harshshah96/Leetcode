static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        int n=nums.size();
        unordered_map<int, int> mp;
        int mxFreq=INT_MIN;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            mxFreq=max(mxFreq , mp[nums[i]]);
        }
        int count=0;
        for(auto &ele:mp){
            if(ele.second == mxFreq) count+=mxFreq;
        }

        return count;
        
    }
};