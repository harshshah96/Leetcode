static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
    int count;
    bool isSafe(int row,int col,vector<string>&ds,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0&&col>=0){
        if(ds[row][col]=='Q') return false;
        row--;
        col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
        if(ds[row][col]=='Q') return false;
        col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n&&col>=0){
            if(ds[row][col]=='Q') return false;
        col--;
        row++;
        }
        return true;
    }
    void fillQueen(int col,int n,vector<vector<string>>&ans,vector<string>&ds){
        if(col==n){
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,ds,n)){
                ds[row][col]='Q';
                fillQueen(col+1,n,ans,ds);
                ds[row][col]='.';
            }
        }
    }
        int totalNQueens(int n) {
            count=0;
            vector<string>ds(n, string(n,'.'));
            vector<vector<string>>ans;
            //   string s(n,'.');
            //   for(int i=0;i<n;i++){
            //       ds[i]=s;
            //   }
    
        fillQueen(0,n,ans,ds);
        return count;
        }
};