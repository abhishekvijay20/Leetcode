class Solution {
private:
    int helper(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (j < 0) return i+1;
        if (i < 0) return j+1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) {
            return dp[i][j] = helper (s, t, i-1, j-1, dp);
        } else {
            int insert = helper (s, t, i, j-1, dp);
            int del = helper (s, t, i-1, j, dp);
            int replace = helper (s, t, i-1, j-1, dp);
            
            return dp[i][j] = 1 + min(replace, min(insert, del));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper (word1, word2, n-1, m-1, dp);
    }
};