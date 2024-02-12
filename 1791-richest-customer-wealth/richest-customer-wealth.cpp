static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();

        int ans=INT_MIN;

        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=0; j<m; j++){
                temp+=accounts[i][j];
            }
            ans=max(ans,temp);
        }

        return ans;
        
    }
};