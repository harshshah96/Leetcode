static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int K;
    int result;

    void solve (int idx , vector<int>&nums, unordered_map<int,int> &mp){
        if(idx >= nums.size()){
            result++;
            return;
        }

        //take
        if(!mp[nums[idx] + K] && !mp[nums[idx] - K]){
            mp[nums[idx]]++;
            solve(idx+1 , nums, mp);
            mp[nums[idx]]--;
        }

        //not take 
        solve(idx+1 , nums, mp);
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        unordered_map<int, int>  mp ;
        result = 0;
        K=k;


        solve( 0 , nums , mp);

        return result-1;
    }
};