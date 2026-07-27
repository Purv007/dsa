class Solution {
public:
    bool func(vector<vector<char>>& board, int r, int c) {
        if (c == 9) { c = 0; r += 1; }
        if (r == 9) return true; 

        if (board[r][c] != '.') {
            return func(board, r, c + 1);
        } else {
            for (int i = 1; i <= 9; ++i) {
                if (isValid(board, r, c, i)) {
                    board[r][c] = char('0' + i);
                    if (func(board, r, c + 1)) return true; 
                    board[r][c] = '.';
                }
            }
            return false;
        }
    }

    bool isValid(const vector<vector<char>>& board, int r, int c, int n) {
        char ch = char('0' + n);
        for (int i = 0; i < 9; ++i) {
            if (board[i][c] == ch) return false;
            if (board[r][i] == ch) return false;
        }
        
        int r1, r2, c1, c2;
        inplace(r, r1, r2);
        inplace(c, c1, c2);

        if (board[r1][c1] == ch) return false;
        if (board[r1][c2] == ch) return false;
        if (board[r2][c1] == ch) return false;
        if (board[r2][c2] == ch) return false;

        return true;
    }

    void inplace(int idx, int &i1, int &i2) {
        if (idx % 3 == 0)      { i1 = idx + 1; i2 = idx + 2; }
        else if (idx % 3 == 1) { i1 = idx - 1; i2 = idx + 1; }
        else                   { i1 = idx - 1; i2 = idx - 2; }
    }

    void solveSudoku(vector<vector<char>>& board) {
        func(board, 0, 0);
    }
};
