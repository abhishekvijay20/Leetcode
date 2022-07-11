class Solution {
private: 
    int helper (string& s1, string& s2, int idx1, int idx2, vector<vector<int>>& dp) {
        if (idx1 < 0 || idx2 < 0) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if (s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = 1 + helper (s1, s2, idx1-1, idx2-1, dp);
        } else {
            return dp[idx1][idx2] = max(helper(s1, s2, idx1, idx2-1, dp), helper(s1, s2, idx1-1, idx2, dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return helper (text1, text2, text1.size()-1, text2.size()-1, dp);
    }
};