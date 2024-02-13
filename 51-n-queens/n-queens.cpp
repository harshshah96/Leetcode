class Solution {
public:
    int n;
    void saveBoard(vector<vector<char>>&board,vector<vector<string>> &ans){

        vector<string> ans1;

        for(int i=0; i<n; i++){
            string a="";
            for(int j=0; j<n; j++){
                if(board[i][j]=='Q') a+='Q';
                else a+='.';
            }
            ans1.push_back(a);
        }
        ans.push_back(ans1);

    }


    bool isSafe(int row, int col, vector<vector<char>>&board){
        
        
        // check row
        for(int i=0; i<n; i++){
            if(board[row][i]=='Q') return false;
        }
        // check col
        for(int i=0; i<n; i++){
            if(board[i][col]=='Q') return false;
        }
        // check top left;
        
        for(int r=row, c=col; r>=0 && c>=0; r--, c--){
            if(board[r][c]=='Q') return false;
        }
        // check top right;
        
        for(int r=row, c=col; r>=0 && c<n; r--, c++){
            if(board[r][c]=='Q') return false;
        }
        // check bottom left;
        
        for(int r=row, c=col; r<n && c>=0; r++, c--){
            if(board[r][c]=='Q') return false;
        }
        // check bottom right;
        
        for(int r=row, c=col; r<n && c<n; r++, c++){
            if(board[r][c]=='Q') return false;
        }

        return true;

    }

    void solve(vector<vector<string>> &ans,vector<vector<char>>&board, int col){
        if(col==n){
            saveBoard(board, ans);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board)){
                board[row][col]='Q';
                solve(ans, board, col+1);
                board[row][col]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int m) {
        n=m;
        vector<vector<string>> ans;
        vector<vector<char>>board(n, vector<char>(n,'.'));

        solve(ans,board,0);

        return ans;

        
    }
};