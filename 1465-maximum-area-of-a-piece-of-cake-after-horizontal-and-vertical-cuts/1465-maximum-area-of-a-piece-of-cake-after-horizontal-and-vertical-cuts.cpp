class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long maxHor = horizontalCuts[0], maxVer = verticalCuts[0];
        
        for (int i=1; i<horizontalCuts.size(); i++) {
            int x = horizontalCuts[i]-horizontalCuts[i-1];
            if (x > maxHor) {
                maxHor = x;
            }
        }
        for (int i=1; i<verticalCuts.size(); i++) {
            int x = verticalCuts[i]-verticalCuts[i-1];
            if (x > maxVer) {
                maxVer = x;
            }
        }
        long long p = maxHor%1000000007;
        long long q = maxVer%1000000007;
        long long ans = ((p)*(q));
        int d = ans%1000000007;
        return d;
    }
};