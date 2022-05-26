class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int r = 0, c = 0, i=0;
        while (n > 1) {
            while (i < n-1) {
                swap(matrix[r][c+i], matrix[r+n-1-i][c]);
                swap(matrix[r+n-1-i][c], matrix[r+n-1][c+n-1-i]);
                swap(matrix[r+n-1][c+n-1-i], matrix[r+i][c+n-1]);
                // swap(matrix[r+i][c+n-1], matrix[r][c+i]);
                i++;
            }
            i = 0;
            n-=2;
            r++, c++;
        }
    }
};