static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:

    void dfs(vector<vector<char>>& grid,int r, int c){
        if(r<0 || c<0 || r>=grid.size()|| c>=grid[0].size() || grid[r][c]!='1') return;
        grid[r][c]='0'; // marks element '5' means it is visited in a connected graph.
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        int count=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }    
        return count;    
    }
};