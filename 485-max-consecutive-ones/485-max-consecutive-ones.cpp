class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0, n = nums.size(), cnt = 0;
        for (int i=1; i<=n; i++) {
            if (nums[i-1] == 1) {
                cnt++;
            } else {
                cnt = 0;
            }
            
            if (cnt > maxCnt) maxCnt = cnt;
        }
        return maxCnt;
    }
};