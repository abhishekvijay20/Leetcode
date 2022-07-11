class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max (dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        for (int i=0, j=s.size()-1; i<j; i++, j--) {
            swap(t[i], t[j]);
        }
        return longestCommonSubsequence(s, t);
    }
};