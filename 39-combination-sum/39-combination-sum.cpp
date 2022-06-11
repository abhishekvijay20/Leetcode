class Solution {
private:
    void helper(vector<int>& candidates, int k, vector<vector<int>>& ans, vector<int>& v, int idx) {
        if (k < 0) return;
        
        if (k == 0) ans.push_back(v);
        
        for (int i=idx; i<candidates.size(); i++) {
            v.push_back(candidates[i]);
            helper(candidates, k-v.back(), ans, v, i);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ans, v, 0);
        return ans;
    }
};