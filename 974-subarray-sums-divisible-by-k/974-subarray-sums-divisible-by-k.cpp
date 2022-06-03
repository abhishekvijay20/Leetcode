class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            int tobeAdded = sum % k;
            if (tobeAdded < 0) tobeAdded += k;
            if (m.find(tobeAdded) != m.end()) {
                ans += m[tobeAdded];
            }
            m[tobeAdded]++;
        }
        return ans;
    }
};