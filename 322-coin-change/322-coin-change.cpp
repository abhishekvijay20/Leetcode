class Solution {
private:
    int helper (vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }
        
        if (amount < 0) return 1e9;
        
        if (dp[idx][amount] != -1) return dp[idx][amount];
        
        int notPick = helper (coins, idx-1, amount, dp);
        int pick = INT_MAX;
        if (amount >= coins[idx]) pick = 1 + helper (coins, idx, amount-coins[idx], dp);
        
        return dp[idx][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = helper (coins, coins.size()-1, amount, dp);
        if (ans >= 1e9) return -1;
        return ans;
    }
};