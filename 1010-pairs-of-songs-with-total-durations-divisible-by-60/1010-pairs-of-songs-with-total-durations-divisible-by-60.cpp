class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), ans = 0;
        unordered_map<int, int> m;
        m[0] = 0;
        for (int i=0; i<n; i++) {
            int a = time[i]%60;
            if (a == 0) {
                ans += m[0];
            } else {
                if (m.find(60-a) != m.end()) {
                    ans += m[60-a];
                }
            }
            m[a]++;
        }
        return ans;
    }
};