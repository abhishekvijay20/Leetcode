class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> backtrack(n, 0);
        
        sort (nums.begin(), nums.end());
        
        int maxi = 1, idx = 0;
        for (int i=0; i<n; i++) {
            backtrack[i] = i;
            for (int j=0; j<i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > maxi) idx = i;
                    maxi = max(maxi, dp[i]);
                    backtrack[i] = j;
                } 
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[idx]);
        while (backtrack[idx] != idx) {
            idx = backtrack[idx];
            ans.push_back(nums[idx]);
        }
        //if (idx == 0 && ans.size() != 0 && ans.back() % nums[0] == 0) ans.push_back(nums[0]);
        
        return ans;
    }
};