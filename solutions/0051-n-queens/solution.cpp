class Solution {
public:
    void func(vector<vector<string>>& res,vector<string>&board,int n,int row){
        if(row==n){
            res.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(valid(board,n,row,i)){
                board[row][i]='Q';
                func(res,board,n,row+1);
                board[row][i]='.';
            }
        }
    }

    bool valid(vector<string>&board,int n,int r,int c){
        for(int i=0;i<r;i++){
            if(board[i][c]=='Q'){
                return false;
            }
        }

        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
    vector<string>board(n,string(n,'.'));
       func(res,board,n,0);
        return res;
    }
};
