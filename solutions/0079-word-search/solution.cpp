class Solution {
public:
    int n,m;
    bool find(int i,int j,int pos,string word,vector<vector<char>>& board){
        if(pos==word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m  || board[i][j]!=word[pos]){
            return false;
        }
        int temp=board[i][j];
        board[i][j]='\0';
        if (find(i + 1, j,pos+1,word,board) || find(i - 1, j,pos+1,word,board) || find(i, j + 1,pos+1,word,board) || find(i, j - 1,pos+1,word,board)) {
            return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        n=board.size(),m=board[0].size();
        char a=word[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res|=find(i,j,0,word,board);
            }
        }
        return res;
    }
};
