class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int minSoFar = INT_MAX;
        for (int i=0; i<prices.size(); i++) {
            minSoFar = min(minSoFar, prices[i]);
            ans = max(ans, prices[i]-minSoFar);
        }
        return ans;
    }
};