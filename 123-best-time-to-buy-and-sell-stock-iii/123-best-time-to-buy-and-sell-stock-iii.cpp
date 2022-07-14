class Solution {
private:
    int helper (vector<int>& prices, int idx, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if (idx == prices.size() || cap == 0) return 0;
        if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        
        if (buy == 1) {
            return dp[idx][buy][cap] = max(-prices[idx] + helper(prices, idx+1, 0, cap, dp), helper(prices, idx+1, 1, cap, dp));
        } else {
            return dp[idx][buy][cap] = max(prices[idx] + helper (prices, idx+1, 1, cap-1, dp), helper(prices, idx+1, 0, cap, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper (prices, 0, 1, 2, dp);
    }
};