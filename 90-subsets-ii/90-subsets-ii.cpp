class Solution {
private:
    void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, int k) {
        ans.push_back(v);
        for (int i=k; i<nums.size(); i++) {
            if (i != k && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(nums, v, ans, i+1);
            v.pop_back();
            
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, v, ans, 0);
        return ans;
    }
};