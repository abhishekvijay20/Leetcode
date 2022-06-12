class Solution {
private:
    void helper (vector<vector<int>>& ans, vector<int> nums, int ind) {
        if (ind >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for (int i=ind; i<nums.size(); i++) {
            if (i != ind && nums[i] == nums[ind]) continue;
            swap(nums[i], nums[ind]);
            helper(ans, nums, ind+1);
            //swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(ans, nums, 0);
        return ans;
    }
};