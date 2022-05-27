class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int r, int c) {
        if (word.size() == 0) return true;
        
        int m = board.size(), n = board[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[0]) return false;
        
        char x = board[r][c];
        board[r][c] = '*';
        string s = word.substr(1);
        bool smallAns = dfs(board, s, r-1, c) || dfs(board, s, r, c+1) || dfs(board, s, r+1, c) || dfs(board, s, r, c-1);
        board[r][c] = x;
        return smallAns;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }
};