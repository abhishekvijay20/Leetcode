class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = INT_MAX/2;
        for (int i=0; i<n; i++) {
            int j=0, k=n-1;
            while (j < k) {
                if (j == i){
                    j++;
                    continue;
                } 
                if (k == i){
                    k--;
                    continue;
                }
                int x = nums[i] + nums[j] +  nums[k];
                
                if (abs(target-x) < abs(target-ans)) {
                    ans = x;
                } 
                
                // cout << ans << endl;
                
                if (nums[j]+nums[k] < target-nums[i]) {
                    j++;
                } else if (nums[j]+nums[k] > target-nums[i]){
                    k--;
                } else {
                    return x;
                }
            }
        }
        return ans;
    }
};