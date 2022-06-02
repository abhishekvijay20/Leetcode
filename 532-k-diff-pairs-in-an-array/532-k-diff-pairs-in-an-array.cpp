class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        map<int, int> m;
        for (int i=0; i<n; i++) {
            m[nums[i]]++;
        }
        for (auto i: m) {
            if (k == 0) {
                if (i.second > 1) ans++;
            } 
            else if (m.find(i.first+k) != m.end()) {
                ans++;
            }
        }
        return ans;
    }
};