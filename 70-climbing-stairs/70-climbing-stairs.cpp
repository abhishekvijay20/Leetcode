class Solution {
private:
    int helper (int n, vector<int>& dp) {
        if (n <= 3) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);        
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};