class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1000000007;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> m;
        for (auto it: arr) m[it]++;
        for (int i=1; i<n; i++) {
            long long cnt = 0;
            for (int j=0; j<i; j++) {
                if (arr[i] % arr[j] == 0) {
                    auto it = m.find(arr[i]/arr[j]);
                    if (it != m.end()) {
                        cnt += (m[arr[j]] * m[arr[i]/arr[j]]);
                    }
                }
            }
            m[arr[i]] += cnt;
        }
        
        long long ans = 0;
        for (auto it: m) ans += it.second;
        return ans % mod;
    }
};