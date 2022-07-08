class Solution {
private:
    int helper (vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (c < 0 || c >= matrix.size()) return INT_MAX;
        if (dp[r][c] != -1) return dp[r][c];
        if (r == matrix.size()-1) {
            return matrix[r][c];
        }
        
        int x = helper(matrix, r+1, c-1, dp);
        int y = helper(matrix, r+1, c, dp);
        int z = helper(matrix, r+1, c+1, dp);
        
        return dp[r][c] = matrix[r][c] + min(x, min(y,z));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i=0; i<n; i++) {
            ans = min(ans, helper(matrix, 0, i, dp));
        }
        
        return ans;
    }
};