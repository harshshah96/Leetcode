static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int t[71][71][71];
    int m,n;
    int solve(vector<vector<int>> &grid , int row, int colR1, int colR2){
        if(row>=n) return 0;

        if(t[row][colR1][colR2]!=-1) return t[row][colR1][colR2];

        int cherry=grid[row][colR1];
        if(colR1!=colR2) cherry+=grid[row][colR2];
        int ans=0;

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int new_col_r1= colR1+i;
                int new_col_r2= colR2+j;
                int new_row=row+1;

                if(new_col_r1>=0 && new_col_r1<m && new_col_r2>=0 && new_col_r2<m){
                    ans=max(ans, solve(grid ,new_row, new_col_r1,new_col_r2));
                }

            }
        }

        return t[row][colR1][colR2]=cherry+ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(t, -1, sizeof(t));

        // robot 1 -> starts from (0,0);
        // robot 2 -> starts from (0, m-1);
        // both reaches to the last row
        // hence number of steps allowed for each robot is (m-1) ;

        return solve(grid, 0,0,m-1);


        
    }
};