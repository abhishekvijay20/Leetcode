class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans1 = INT_MIN;
        int minSoFar1 = INT_MAX;
        int ans2 = INT_MIN;
        int minSoFar2 = INT_MAX;
        for (int i=0; i<n; i++) {
            minSoFar1 = min(minSoFar1, prices[i]);
            ans1 = max(ans1, prices[i]-minSoFar1);
            minSoFar2 = min(minSoFar2, prices[i]-ans1);
            ans2 = max(ans2, prices[i]-minSoFar2);
        }
        return ans2;
    }
};