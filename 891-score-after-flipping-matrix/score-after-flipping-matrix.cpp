static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        //check if rows start with one or not
        //if not than flip th numbers.

        for(int i=0; i<n; i++){
            if(grid[i][0]==0){//flip the row elements
                for(int j=0; j<m; j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }
        }

        //operations on columns
        
        
        for(int j=0; j<m; j++){

            int noz=0;
            int noo=0;

            for(int i=0; i<n; i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
            if(noo<noz){
                for(int i=0; i<n;i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]=0;
                }
            }

        }

        //Sum

        int sum=0;
        for(int i=0; i<n; i++){
            int x=1;
            for(int j=m-1; j>=0; j--){
                 sum += grid[i][j] * x;
                x *= 2;
            }
        }

        return sum;
        
    }
};