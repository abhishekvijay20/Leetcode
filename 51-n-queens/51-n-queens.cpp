class Solution {
private:
    bool isValid(vector<string>& v, int r, int c, int n) {
        int i = r, j = c;
        while (i >= 0) {
            if (i != r && v[i][c] == 'Q') return false; 
            i--;
        }
        i = r, j = c;
        while (i >= 0 && j < n) {
            if (i != r && j != c && v[i][j] == 'Q') return false;
            i--;
            j++;
        }
        i = r, j = c;
        while (i >= 0 && j >= 0) {
            if (i != r && j != c && v[i][j] == 'Q') return false;
            i--;
            j--;
        }
        return true;
    }
    
    void helper(vector<vector<string>>& ans, vector<string>& v, int n, int i) {
        if (i >= n) {
            ans.push_back(v);
            return;
        }
        
        for (int j=0; j<n; j++) {
            if (isValid(v, i, j, n)) {
                v[i][j] = 'Q';
                helper(ans, v, n, i+1);
                v[i][j] = '.';
            }
        }
    }
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v;
        string s = "";
        for (int i=0; i<n; i++) {
            s += ".";
        }
        for (int i=0; i<n; i++) {
            v.push_back(s);
        }
        helper(ans, v, n, 0);
        
        return ans;
    }
};