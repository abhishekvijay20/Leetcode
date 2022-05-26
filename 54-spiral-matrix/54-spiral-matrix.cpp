class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int uR=0, lR=matrix.size()-1, lC=0, rC=matrix[0].size()-1;
        
        vector<int> ans;
        int r = 0, c = 0;
        int n = matrix.size()*matrix[0].size();
        
        int i = 0;
        while (i < n) {
            while (i < n && c <= rC) {
                ans.push_back(matrix[r][c]);
                i++, c++;
            }
            r++, c--, uR++;
            while (i < n && r <= lR) {
                ans.push_back(matrix[r][c]);
                i++, r++;
            }
            r--, c--, rC--;
            while (i < n && c >= lC) {
                ans.push_back(matrix[r][c]);
                i++, c--;
            }
            r--, c++, lR--;
            while (i < n && r >= uR) {
                ans.push_back(matrix[r][c]);
                i++, r--;
            }
            r++, c++, lC++;
        }
        return ans;
    }
};