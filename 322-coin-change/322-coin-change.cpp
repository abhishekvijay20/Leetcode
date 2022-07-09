class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 1e9));
        for (int i=0; i<=amount; i++) {
            if (i % coins[0] == 0) dp[0][i] = i/coins[0]; 
        }
        
        for (int i=1; i<coins.size(); i++) {
            for (int j=0; j<=amount; j++) {
                int notPick = dp[i-1][j];
                int pick = INT_MAX;
                if (j >= coins[i]) pick = 1 + dp[i][j-coins[i]];
                
                dp[i][j] = min (pick, notPick);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if (ans >= 1e9) return -1;
        return ans;
    }
};