class Solution {
public:
    void neighbors(vector<vector<int>>& board, int r, int c, int& cnt1) {
        int m = board.size(), n = board[0].size();
        for (int i=r-1; i<=r+1; i++) {
            if (i < 0 || i >= m) continue;
            for (int j=c-1; j<=c+1; j++) {
                if (j < 0 || j >= n) continue;
                if (i == r && j == c) continue;
                if (board[i][j] == 1) cnt1++;
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> aux(m, vector<int>(n, 0));
                
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int cnt1 = 0;
                neighbors(board, i, j, cnt1);
                if (board[i][j] == 0) {
                    if (cnt1 == 3) aux[i][j] = 1;
                } else {
                   if (cnt1 ==2 || cnt1 ==3) aux[i][j] = 1;
                }
            }
        }
        
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) board[i][j] = aux[i][j];
    }
};