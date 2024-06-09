static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count = 0;
        mp[0]=1;
        //sum of the elements of the subarray is a multiple of k
        int sum = 0 ;
        int n = nums.size();

        for(int i = 0; i < n ; i++){
            sum+=nums[i];
            int a = sum%k < 0 ? (sum%k + k) : sum%k ;
            if(mp.find(a)!=mp.end()) count+=mp[a];
            // if(mp.find(a-k)!=mp.end()) count+= mp[a-k];
            mp[a]++;
        }

        return count;

    }
};

