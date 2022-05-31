class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        map<int,int> mp1;
        for(int i = 0 ; i<n ; i++){
            if(mp1.find(nums[i]) == mp1.end()){
                mp1[nums[i]]++;
            }
            else{
                return nums[i];
                break;
            }            
        }
        return -1;
    }
};