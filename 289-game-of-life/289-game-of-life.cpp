class Solution {
public:
    void neighbors(vector<vector<int>>& board, int r, int c, int& cnt1) {
        int m = board.size(), n = board[0].size();
        for (int i=r-1; i<=r+1; i++) {
            if (i < 0 || i >= m) continue;
            for (int j=c-1; j<=c+1; j++) {
                if (j < 0 || j >= n) continue;
                if (i == r && j == c) continue;
                if (board[i][j] == 1 || board[i][j] == 3) cnt1++;
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();             
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int cnt1 = 0;
                neighbors(board, i, j, cnt1);
                if (board[i][j] == 0) {
                    if (cnt1 == 3) board[i][j] = 2;
                } else {
                   if (!(cnt1 ==2 || cnt1 ==3)) board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};