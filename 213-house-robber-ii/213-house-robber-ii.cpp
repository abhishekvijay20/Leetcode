class Solution {
private:
    int helper(vector<int>& nums, int start, int end) {
        int n = nums.size();
        vector<int> dp(n-1);
        dp[0] = nums[start];
        for (int i=1; i<=end-start; i++) {
            int pick = nums[i+start];
            if (i >= 2) pick += dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[end-start];        
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int a = helper(nums, 0, n-2);
        int b = helper(nums, 1, n-1);
        
        return max(a, b);
    }
};