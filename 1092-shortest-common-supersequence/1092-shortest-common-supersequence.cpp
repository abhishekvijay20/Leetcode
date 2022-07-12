class Solution {
private:
    string helper(string text1, string text2) {
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
        int l = n + m - dp[n][m];
        string rAns = "";
        int i=n, j=m;
        while (i > 0 && j > 0) {
            if (text1[i-1] == text2[j-1]) {
                rAns += text1[i-1];
                i--, j--;
            } else {
                if (dp[i][j-1] > dp[i-1][j]) {
                    rAns += text2[j-1];
                    j--;
                } else {
                    rAns += text1[i-1];
                    i--;
                }
            }
        }
        // cout << rAns << endl;
        while (i > 0) {
            rAns += text1[i-1];
            i--;
            
        } 
        while (j > 0){
            rAns += text2[j-1];
            j--;
        }    
        return rAns;
    }    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = helper(str1, str2);
        for (int i=0, j=ans.size()-1; i<j; i++, j--) {
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};