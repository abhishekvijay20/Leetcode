class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), l = -1, r = -1;
        if (n == 0) return {l, r};
        int i=0, j=n-1;
        while (i+1 < j) {
            int mid = (i+j)/2;
            if (nums[mid] >= target) {
                j = mid;
            } else {
                i = mid;
            }
        }
        
        if (nums[i] == target) {
            l = i;
        } else if (nums[j] == target) {
            l = j;     
        }
        cout << "left " << l << endl;
        
        i = 0, j = n-1;
        while (i+1 < j) {
            int mid = (i+j)/2;
            if (nums[mid] <= target) {
                i = mid;
            } else {
                j = mid;
            }
        }
        
        if (nums[j] == target) {
            r = j;
        } else if (nums[i] == target) {
            r = i;     
        }
        cout << "right " << r << endl;
        
        return {l, r};
    }
};