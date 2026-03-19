class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<vector<int>> prefX(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> prefY(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                prefX[i + 1][j + 1] = prefX[i][j + 1] + prefX[i + 1][j] - prefX[i][j] + (grid[i][j] == 'X');
                prefY[i + 1][j + 1] = prefY[i][j + 1] + prefY[i + 1][j] - prefY[i][j] + (grid[i][j] == 'Y');

                if (prefX[i + 1][j + 1] > 0 && prefX[i + 1][j + 1] == prefY[i + 1][j + 1]) {
                    count++;
                }
            }
        }

        return count;
    }
};