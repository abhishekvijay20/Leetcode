class Solution {
private:
    int helper (vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0;
        if (dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            return dp[idx][prevIdx+1] = max(helper(nums, idx+1, prevIdx, dp), 1 + helper(nums, idx+1, idx, dp));
        } else {
            return dp[idx][prevIdx+1] = helper (nums, idx+1, prevIdx, dp);
        }
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(nums,0, -1, dp);
    }
};