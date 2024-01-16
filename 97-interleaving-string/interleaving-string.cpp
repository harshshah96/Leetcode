static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    
    bool solve(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp){

        if(i+j==s3.size()) return true;

        if(dp[i][j]!=INT_MIN) return dp[i][j];


        bool solve1= (i<s1.length() && s1[i]==s3[i+j]) ? solve(s1,s2,s3,i+1,j, dp) : false;
        bool solve2= (j<s2.length() && s2[j]==s3[i+j]) ? solve(s1,s2,s3,i,j+1, dp) : false;

        return dp[i][j]=solve1 || solve2;
        

    }
    bool isInterleave(string s1, string s2, string s3) {

        if(s3.length()!=s1.length()+s2.length()) return false;

        vector<vector<int>> dp;
        dp.clear();
        dp.resize(s1.length()+1, vector<int> (s2.length()+1, INT_MIN));


        return solve(s1,s2,s3,0,0,dp);
        
    }
};