static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int>arr;
    vector<int> dp;
    int f(int i){
        if(i==0) return 1;
        int mx=INT_MIN;
        if(dp[i]!=-1) return dp[i];
        for(int j=0; j<=i-1; j++){
            if(arr[j]<arr[i]) mx=max(mx,f(j));
        }
        if(mx == INT_MIN) return dp[i]=1;
        return dp[i]=1 + mx;
    }
    int lengthOfLIS(vector<int>& nums) {
        arr=nums;
        dp.clear();
        dp.resize(arr.size(),-1);
        dp[0]=1;
        int ans=INT_MIN;
        for(int i=0; i<nums.size();i++){
            ans=max(ans,f(i));
        }
        return ans;
    }
};