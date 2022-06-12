class Solution {
private:
    vector<vector<int>> helper(vector<int>& nums, int k, int ind) {
        if (k == 1) {
            vector<vector<int>> v;
            for (int i=ind; i<nums.size(); i++) {
                v.push_back({nums[i]});
            }
            return v;
        }
        
        if (ind + k -1 >= nums.size()) {
            return {};
        }

        vector<vector<int>> smallAns1 = helper(nums, k, ind+1);
        vector<vector<int>> smallAns2 = helper(nums, k-1, ind+1);
        
        vector<vector<int>> ans;
        for (int i=0; i<smallAns1.size(); i++) {
            ans.push_back(smallAns1[i]);
        }
        for (int i=0; i<smallAns2.size(); i++) {
            smallAns2[i].push_back(nums[ind]);
            ans.push_back(smallAns2[i]);
        }
        return ans;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i=1; i<=n; i++) {
            nums.push_back(i);
        }        
        return helper(nums, k, 0);
    }
};