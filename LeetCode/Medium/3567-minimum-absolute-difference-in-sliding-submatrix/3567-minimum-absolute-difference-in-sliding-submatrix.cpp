class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        vector<int> vals;
        vals.reserve(k * k);
        
        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vals.clear();
                for (int x = i; x < i + k; ++x) {
                    for (int y = j; y < j + k; ++y) {
                        vals.push_back(grid[x][y]);
                    }
                }
                
                sort(vals.begin(), vals.end());
                
                int min_d = 2147483647;
                bool found = false;
                
                for (size_t v = 1; v < vals.size(); ++v) {
                    if (vals[v] != vals[v - 1]) {
                        min_d = min(min_d, vals[v] - vals[v - 1]);
                        found = true;
                    }
                }
                
                ans[i][j] = found ? min_d : 0;
            }
        }
        
        return ans;
    }
};