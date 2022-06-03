class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canReach(n, false);
        canReach[n-1] = true;
            
        for (int i=n-2; i>=0; i--) {
            
            for (int j=1; j<=nums[i]; j++) {
                
                if (i+j < n && canReach[i+j] == true) {
                    canReach[i] = true;
                    break;
                }
            }
        }

        return canReach[0];
    }
};


        // int n = nums.size();
        // vector<bool> canReach(n);
        // canReach[n-1] = true;
        // for (int i=0; i<n; i++) {
        //     cout << canReach[i] << " ";
        // }      
        // cout << endl;
        // for (int i=n-2; i >= 0; i--) {
        //     if (nums[i] >= 1) {
        //         for (int j=1; j<=nums[i]; j++) {
        //             if (i+j < n && nums[i+j] == true) {
        //                 cout << "aaya" << endl;
        //                 nums[i] = true;
        //                 break;
        //             } else {
        //                 canReach[i] = false;
        //             }
        //         }
        //     } else {
        //         cout << "aaya" << endl;
        //         canReach[i] = false;
        //     }
        // }
        // for (int i=0; i<n; i++) {
        //     cout << canReach[i] << " ";
        // }
        // return canReach[0];