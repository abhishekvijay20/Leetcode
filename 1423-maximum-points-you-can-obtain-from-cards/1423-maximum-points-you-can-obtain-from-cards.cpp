class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max = INT_MIN, sum = 0, n = cardPoints.size();
        for (int i=0; i<k; i++) {
            sum += cardPoints[i];
        }
        int newSum = sum;
        for (int i=1; i<=k; i++) {
            newSum -= cardPoints[k-i];
            newSum += cardPoints[n-i];
            if (newSum > sum) {
                sum = newSum;
            }
        }
        return sum;
    }
};