
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
        int A = solve(n-1,0,abs+1,dp);
        int L = solve(n-1,con_late+1,abs,dp);
        int P = solve(n-1,0,abs,dp);

        return dp[n][abs][con_late]=((A + L)%M + P) % M;


    }
    int checkRecord(int n) {
        int t[n+1][2][3];

        for(int A = 0 ; A<=1; A++){
            for(int L = 0;  L<=2 ; L++){
                t[0][A][L] = 1;
            }
        }
        for(int i=1;i<=n; i++){
            for(int A = 0; A<=1; A++){
                for(int L = 0; L<=2; L++){
                    // long result=0;
                    long result = t[i-1][A][0] ; // present
                    result += ( L+1<=2 ? t[i-1][A][L+1] : 0 ); // Late
                    result += ( A+1<=1 ? t[i-1][A+1][0] : 0 ); // Absent
                    
                    t[i][A][L] = result % M;
                }
            }
        }

        return t[n][0][0];
    }
};