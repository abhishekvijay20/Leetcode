class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        string ans = "";
        int fact = 1;
        for (int i=1; i<n; i++) {
            fact *= i;
            v.push_back(i);
        }
        v.push_back(n);
        k--;
        while (ans.size() != n) {
            if (v.size() == 1) {
                ans += to_string(v[0]);
                break;
            }
            ans += to_string(v[k/fact]);
            v.erase(v.begin() + k/fact);
            k = k % fact;
            fact /= v.size();
        }
        
        return ans;
    }
};