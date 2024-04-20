static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    static bool dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& vis, int parentX, int parentY) {
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m
            && grid[nrow][ncol] == grid[x][y] && !(parentX == nrow && parentY == ncol)){
                if(vis[nrow][ncol]) return true;
                else {
                    bool cycle = dfs(nrow,ncol,grid,vis,x,y);
                    if(cycle) return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0) {
                    flag = dfs(i, j, grid, vis, -1, -1);
                }
                if(flag) break;
            }
            if(flag) break;
        }
        return flag;
    }
};