class Solution {
public:
    int fib(int n) {
        vector<int> v(n+1);
        v[0] = 0;
        if (n >= 1) v[1] = 1;
        for (int i=2; i<=n; i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
};