class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        vector<vector<int>> ans;
        sort (nums.begin(), nums.end());
        for (int i=0; i<n; i++) {
            for (int j=n-1; j>=i+3; j--) {
                int l = i+1, r = j-1;
                while (l < r) {
                    if (nums[i] + nums[j] < target - (nums[l] + nums[r])) {
                        l++;
                    } else if (nums[i] + nums[j] > target - (nums[l] + nums[r])) {
                        r--;                        
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l+1] == nums[l]) l++;
                        while (l < r && nums[r-1] == nums[r]) r--;
                        l++;
                        r--;
                    }
                }
                while (j-1 >= i+3 && nums[j-1] == nums[j]) j--;
            }
            while (i+1 <n && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};