class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, reach = 0;
        while (i < n && i <= reach) {
            reach = max (reach, i+nums[i]);
            i++;
        }
        return i == n;
    }
};
