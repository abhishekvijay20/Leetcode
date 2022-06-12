class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int> v, int k, int n, int ind) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }
        
        for (int i=ind; i<n; i++) {
            v.push_back(i+1);
            helper(ans, v, k, n, i+1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans, v, k, n, 0);
        return ans;
    }
};