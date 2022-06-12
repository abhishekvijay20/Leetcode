class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
        int sum = 0;
        int maxi = INT_MIN, l = 0;
        for (int i=0; i<nums.size(); ) {
            if (m.find(nums[i]) == m.end()) {
                sum += nums[i];
                m[nums[i]] = i;
                maxi = max(sum, maxi);
                i++;
            } else {
                int ind = m[nums[i]];
                while (l <= ind) {
                    sum -= nums[l];
                    m.erase(nums[l]);
                    l++;
                }
            }
        }
        return maxi;
    }
};