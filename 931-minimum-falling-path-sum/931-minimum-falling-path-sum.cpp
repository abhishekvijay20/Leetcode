class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i=0; i<n; i++) {
            dp[n-1][i] = matrix[n-1][i];
        }
        
        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<n; j++) {
                int x = INT_MAX, y = dp[i+1][j], z = INT_MAX;
                if (j-1 >= 0) x = dp[i+1][j-1];
                if (j+1 < n) z = dp[i+1][j+1];
                
                dp[i][j] = matrix[i][j] + min(x, min(y,z));
            }
        }
        
        for (int i=0; i<n; i++) {
            ans = min(ans, dp[0][i]);
        }
        
        return ans;
    }
};