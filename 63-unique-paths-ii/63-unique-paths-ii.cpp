class Solution {
private:
    int helper(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) return 1;
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int left = helper(obstacleGrid, i, j-1, dp);
        int up = helper(obstacleGrid, i-1, j, dp);
        
        return dp[i][j] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;
        } else {
            dp[0][0] = 0;
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = ( (dp[i][j-1] != 0) ? 1 : 0);
                } else if (j == 0) {
                    dp[i][j] = ( (dp[i-1][j] != 0) ? 1 : 0);
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                
            }
        }
        
        return dp[m-1][n-1];
    }
};