#define ll long long int
#define mod 1000000007
static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<vector<int>> dp;
    int f(int n, int k, int target){
        
        if(target==0 and n==0) return 1;
        if(n==0) return 0;

        if(dp[n][target]!=-1) return dp[n][target];
        
        int count=0;

        for(int i=1; i<=k; i++){
            if(target-i<0) break;
            count = (count%mod + f(n-1, k, target-i)%mod)%mod;
        }
        return dp[n][target] = count%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35,vector<int>(1005,-1));
        return f(n,k,target);
    }
};