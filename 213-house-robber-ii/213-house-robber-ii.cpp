class Solution {
private:
    int helper (vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start == end) return nums[start];
        if (start > end) return 0;
        if (dp[start] != -1) return dp[start];
        
        int pick = nums[start] + helper(nums, start+2, end, dp);
        int notPick = helper(nums, start+1, end, dp);
        
        return dp[start] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, -1);
        int a = helper(nums, 0, n-2, dp);
        fill(dp.begin(), dp.end(), -1);
        int b = helper(nums, 1, n-1, dp);
        return max(a, b);
    }
};