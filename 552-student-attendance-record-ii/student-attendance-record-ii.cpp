
static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;

}();class Solution {
public:
    int M = 1000000007;
    int solve(int n , int con_late, int abs, vector<vector<vector<int>>> &dp){
        if(con_late > 2 || abs>1) return 0;
        if(n==0) return 1;

        if(dp[n][abs][con_late]!=-1) return dp[n][abs][con_late];
        int A = (solve(n-1,0,abs+1,dp))%1000000007;
        int L = (solve(n-1,con_late+1,abs,dp))%1000000007;
        int P = solve(n-1,0,abs,dp)%1000000007;

        return dp[n][abs][con_late]=((A + L)%M + P) % M;


    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return solve(n,0,0,dp);
        
    }
};