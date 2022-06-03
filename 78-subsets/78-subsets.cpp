class Solution {
public:
    vector<vector<int>> helper (vector<int>& nums, int k) {
        if (k == nums.size()-1) {
            return {{}, {nums[k]}};
        }
        
        vector<vector<int>> smallAns = helper (nums, k+1);
        
        vector<vector<int>> ans;
        for (int i=0; i<smallAns.size(); i++) {
            ans.push_back(smallAns[i]);
        }
        for (int i=0; i<smallAns.size(); i++) {
            vector<int> v = smallAns[i];
            v.push_back(nums[k]);
            ans.push_back(v);
        }
        
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper (nums, 0);
    }
};