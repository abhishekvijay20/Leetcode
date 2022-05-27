class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1;
        for (int i=1; i<n; i++) {
            if (nums[i] == nums[i-1]) {
                count++;
                if (count > n/2) {
                    return nums[i];
                }
            } else {
                count = 1;
            }
        }
        return nums[0];
    }
};