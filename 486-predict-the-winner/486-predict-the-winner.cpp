class Solution {
private:
    int maxScore(vector<int>& nums, int i, int j, bool flag) {
        if (i > j) {
            return 0;
        }
        if (flag) {
            return max(nums[i] + maxScore(nums, i+1, j, !flag), nums[j] + maxScore(nums, i, j-1, !flag));
        } else {
            return min(maxScore(nums, i+1, j, !flag), maxScore(nums, i, j-1, !flag));
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int p1 = maxScore(nums, 0, nums.size()-1, true);
        int p2 = sum - p1;
        return p1 >= p2;
    }
};