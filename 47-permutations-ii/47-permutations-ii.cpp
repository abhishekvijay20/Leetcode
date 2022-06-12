class Solution {
private:
    bool checkmiddle(vector<int>& nums, int i , int begin){
        for(int k = begin; k<i; k++)
            if(nums[i] == nums[k])
                return true;
        return false;
    }
    void helper (vector<vector<int>>& ans, vector<int>& nums, int ind) {
        if (ind >= nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        
        for (int i=ind; i<nums.size(); i++) {
            if ((i != ind && nums[i] == nums[ind]) || checkmiddle(nums, i, ind)) continue;
            swap(nums[i], nums[ind]);
            helper(ans, nums, ind+1);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(ans, nums, 0);
        return ans;
    }
};