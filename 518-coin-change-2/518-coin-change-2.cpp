class Solution {
private:
    int helper (vector<int>& coins, int idx, int k, vector<vector<int>>& dp) {
        if (k == 0) return 1;
        if (idx == 0) {
            if (k % coins[0] == 0) return 1;
            else return 0;
        }
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int notPick = helper(coins, idx-1, k, dp);
        int pick = 0;
        if (k >= coins[idx]) pick = helper (coins, idx, k-coins[idx], dp);
        
        return dp[idx][k] = pick + notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return helper (coins, coins.size()-1, amount, dp);
    }
};