class Solution {
private:
    bool isValid(vector<vector<char>>& board, int r, int c, int x) {
        for (int i=0; i<9; i++) {
            if (i != c && board[r][i] == x) return false;
        }
        
        for (int i=0; i<9; i++) {
            if (i != r && board[i][c] == x) return false;
        }
        
        int rTop = r - (r%3), rBottom = rTop + 2, cLeft = c - (c%3), cRight = cLeft + 2;
        for (int i=rTop; i<=rBottom; i++) {
            for (int j=cLeft; j<=cRight; j++) {
                if (i != r && j != c && board[i][j] == x) return false;
            }
        }
        
        return true;
    }
     
    bool helper (vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    for (char x='1'; x<='9'; x++) {
                        if (isValid(board, i, j, x)) {
                            board[i][j] = x;
                            if (helper(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};