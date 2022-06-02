class Solution {
public:
    int areaIsland(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int a = areaIsland(grid, r+1, c); 
        int b = areaIsland(grid, r, c+1);
        int p = areaIsland(grid, r-1, c);
        int q = areaIsland(grid, r, c-1);
        
        return a+b+p+q+1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    int area = areaIsland(grid, i, j);
                    // cout << area << endl;
                    if (area > maxArea) maxArea = area;
                }
            }
        }
        return maxArea;
    }
};