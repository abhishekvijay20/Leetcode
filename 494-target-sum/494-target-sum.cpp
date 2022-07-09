class Solution {
private:
    int helper (vector<int>& nums, int idx, int target) {
        if (idx == 0) {
            if (nums[0] == 0 && target == 0) return 2; 
            if (nums[0] == target) return 1;
            if (nums[0] == -target) return 1;
            return 0;
        }
        
        int plus = helper (nums, idx-1, target-nums[idx]);
        int minus = helper (nums, idx-1, target+nums[idx]);
        
        return plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper (nums, nums.size()-1, target);
    }
};