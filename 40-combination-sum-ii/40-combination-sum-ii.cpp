class Solution {
private:
    void helper(vector<int>& candidates, int k, vector<vector<int>>& ans, vector<int> v, int idx) {
        if (k == 0) ans.push_back(v);
        if (k < 0) return;
        
        for (int i=idx; i<candidates.size(); i++) {
            if (i != idx && candidates[i-1] == candidates[i]) continue;
            v.push_back(candidates[i]);
            helper(candidates, k-v.back(), ans, v, i+1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, ans, v, 0);
        return ans;
    }
};