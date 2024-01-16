class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string s1, string s2, string s3, int i, int j, int k){

        if(k==s3.size()) return true;

        if(dp[i][j]!=INT_MIN) return dp[i][j];


        bool solve1= s1[i]==s3[k] ? solve(s1,s2,s3,i+1,j,k+1) : false;
        bool solve2= s2[j]==s3[k] ? solve(s1,s2,s3,i,j+1,k+1) : false;

        return dp[i][j]=solve1 || solve2;
        

    }
    bool isInterleave(string s1, string s2, string s3) {

        if(s3.length()!=s1.length()+s2.length()) return false;
        dp.clear();
        dp.resize(s1.length()+1, vector<int> (s2.length()+1, INT_MIN));


        return solve(s1,s2,s3,0,0,0);
        
    }
};