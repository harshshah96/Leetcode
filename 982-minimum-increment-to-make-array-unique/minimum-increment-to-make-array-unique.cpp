
static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;

        for(int i = 0; i<n ; i++){
            mp[nums[i]]++;
        }

        long long count = 0;

        for(auto ele:mp){

            int freq = ele.second;
            int value = ele.first;

            if(freq>1){
                count += (freq-1);
                mp[value+1] += (freq-1);
                ele.second = 1;
            }
        }
        return count ; 
    }
};