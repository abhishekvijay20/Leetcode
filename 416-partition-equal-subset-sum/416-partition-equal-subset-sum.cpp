class Solution {
private:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool>>dp (n, vector<bool>(k+1, false));
        for (int i=0; i<n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= k) dp[0][arr[0]] = true; 

        for (int i=1; i<n; i++) {
            for (int j=1; j<=k; j++) {
                bool notTake = dp[i-1][j];
                bool take = false;
                if (arr[i] <= j) {
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take || notTake; 
            }
        }
        return dp[n-1][k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // if (nums.size() < 2) return false;
        if (sum % 2 != 0) {
            return false;
        }
        return subsetSumToK(nums.size(), sum/2, nums);
    }
};