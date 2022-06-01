class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i=0; i<n; i++) {
            if (m.find(nums[i]) != m.end()) {
                return nums[i];
            } 
            m[nums[i]]++;
        }
        return 0;
    }
};