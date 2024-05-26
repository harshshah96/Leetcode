
static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();class Solution {
public:

    long long solve(int n , int con_late, int abs, vector<vector<vector<int>>> &dp){
        if(con_late > 2 || abs>1) return 0;
        if(n<=0) return 1;

        if(dp[n][abs][con_late]!=-1) return dp[n][abs][con_late];
        long long absent = (solve(n-1,0,abs+1,dp))%1000000007;
        long long late = (solve(n-1,con_late+1,abs,dp))%1000000007;
        long long present = solve(n-1,0,abs,dp)%1000000007;

        return dp[n][abs][con_late]=(((absent)%1000000007) + ((late)%1000000007) + ((present)%1000000007)) % (1000000007);


    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(n,0,0,dp);
        
    }
};