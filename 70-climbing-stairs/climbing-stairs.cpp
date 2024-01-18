static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<int> dp;
    int f(int n, int i){
        if(i>=n) return 0;
        if(i==n-1) return 1;
        if(i==n-2) return 2;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=f(n,i+1)+f(n,i+2);
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(n,-1);
        return f(n,0);

    }
};