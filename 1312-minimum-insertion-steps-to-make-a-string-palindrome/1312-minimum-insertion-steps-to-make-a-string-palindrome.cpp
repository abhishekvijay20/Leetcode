class Solution {
private :
    int lcs(string& str1, string& str2, int idx1, int idx2) {
        int n = idx1+1, m = idx2+1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        for(int i=0, j=n-1; i<j; i++, j--) {
            swap(t[i], t[j]);
        }
        int common = lcs(s, t, n-1, n-1);
        return n - common;
    }
};