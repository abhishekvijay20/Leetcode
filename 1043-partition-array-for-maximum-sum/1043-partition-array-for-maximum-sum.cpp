class Solution {
private:
    int helper (vector<int>& arr, int i, int k, int n, vector<vector<int>>& dp) {
        if (i == arr.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        
        int len = 0, maxi = INT_MIN, ans = INT_MIN;
        for (int j=i; j < min(n, i+k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len*maxi) + helper (arr, j+1, k, n, dp);
            ans = max(ans, sum);
        }
        return dp[i][k] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return helper (arr, 0, k, n, dp);
    }
};