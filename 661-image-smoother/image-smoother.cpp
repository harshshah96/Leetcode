static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> dir;
        dir={ {-1,-1} , {-1,0} , {-1,1},
               {0,-1} , {0,0} , {0,1},
               {1,-1} , {1,0} , {1,1}  };
        vector<vector<int>> ans(m,vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int avg=0;
                int a=0;
                for(int k=0; k<dir.size(); k++){
                    if(i+dir[k][0]>=0 && i+dir[k][0]<m && j+dir[k][1]>=0 && j+dir[k][1]<n){
                        avg+=img[i+dir[k][0]][j+dir[k][1]];
                        a++;
                    }
                }
                avg=avg/a;
                ans[i][j]=avg;
            }
        }

        return ans;
        
    }
};