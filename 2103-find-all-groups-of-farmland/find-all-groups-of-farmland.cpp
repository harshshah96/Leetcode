static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs (vector<vector<int>>& land, int i, int j , int &i2, int &j2){
        land[i][j]=0;

        i2=max(i2,i);
        j2=max(j2,j);

        for(auto &ele : dir){
            int i_=i + ele[0];
            int j_=j + ele[1];

            if(i_>=0 && i_<land.size() && j_>=0 && j_<land[0].size() && land[i_][j_]==1) dfs(land,i_,j_, i2,j2);
        }
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(land[i][j]==1){

                    int i2=0;
                    int j2=0;
                    dfs(land, i, j, i2, j2);
                    ans.push_back({i,j,i2,j2});
                }
            }
        }
        return ans;
        
    }
};