class Solution {
private:
    void helper(int n, int ind, vector<int>& nums, int& ans) {
        if (ind == nums.size()) {
            ans++;
            return;
        }
        
        for (int i=ind; i<n; i++) {
            swap(nums[ind], nums[i]);
            if (nums[ind] % (ind+1) == 0 || (ind+1) % nums[ind] == 0) {
                helper(n, ind+1, nums, ans);
            }
            swap(nums[ind], nums[i]);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> v;
        for (int i=0; i<n; i++) {
            v.push_back(i+1);
        }
        int ans = 0;
        helper(n, 0, v, ans);
        return ans;
    }
};