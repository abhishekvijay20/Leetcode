class Solution {
private:
    int helper (vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for (int k=i; k<=j; k++) {
            int cost = (cuts[j+1] - cuts[i-1]) + helper (cuts, i, k-1, dp) + helper (cuts, k+1, j, dp);
            mini = min (mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        return helper (cuts, 1, c, dp);
    }
};