class Solution {
private:
    int helper(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (i == word1.size() && j == word2.size()) return 0;
        if (i == word1.size()) return word2.size() - j;
        if (j == word2.size()) return word1.size() - i;
        
        if (dp[i][j] != 1000) return dp[i][j];
        
        if (word1[i] == word2[j]) {
            return  helper(word1, word2, i+1, j+1, dp);
        } 
        
        dp[i][j] = 1 + min (helper(word1, word2, i+1, j, dp), helper(word1, word2, i, j+1, dp));
        
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 1000));
        return helper(word1, word2, 0, 0, dp);
    }
};