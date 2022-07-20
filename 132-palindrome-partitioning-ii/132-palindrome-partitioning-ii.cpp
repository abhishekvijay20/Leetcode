class Solution {
private:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    int helper (string& s, int i, int n, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int mini = INT_MAX;
        for (int j=i; j<n; j++) {
            if (isPalindrome(i, j, s)) {
                int cost = 1 + helper (s, j+1, n, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper (s, 0, n, dp) - 1;
    }
};