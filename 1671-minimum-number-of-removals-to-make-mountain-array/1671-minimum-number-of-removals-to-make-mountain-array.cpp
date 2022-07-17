class Solution {
private:
    vector<int> helper1 (vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return dp;
    }    
    vector<int> helper2 (vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i=n-2; i>=0; i--) {
            for (int j=n-1; j>i; j--) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return dp;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1 = helper1(nums);
        vector<int> dp2 = helper2(nums);
        
        int maxi = 0;
        for (int i=0; i<n; i++) {
            if (dp1[i] >= 2 && dp2[i] >= 2) {
                maxi = max(maxi, dp1[i]+dp2[i]-1);
            }
        }
        
        return n - maxi;
    }
};