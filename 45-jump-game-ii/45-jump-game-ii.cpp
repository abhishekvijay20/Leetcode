class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) return 1;
        
        vector<int> aux(n, 0);
        
        if (nums[n-2] != 0) aux[n-2] = 1;
        else aux[n-2] = 10000;
        
        for (int i=n-3; i>=0; i--) {
            int mini = 10000;
            for (int j=0; j < min(nums[i], n-i-1); j++) {
                if (aux[i+j+1] < mini) {
                    mini = aux[i+j+1];
                }
            }
            aux[i] = mini+1;
        }
        
        // for (int i=0; i<n; i++) {
        //     cout << aux[i] << " ";
        // }
        return aux[0];
    }
};