class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        for (int i = 0; i < k / 2; i++) {
            int row1 = x + i;
            int row2 = x + k - 1 - i;
            
            for (int j = y; j < y + k; j++) {
                swap(grid[row1][j], grid[row2][j]);
            }
        }
        
        return grid;
    }
};