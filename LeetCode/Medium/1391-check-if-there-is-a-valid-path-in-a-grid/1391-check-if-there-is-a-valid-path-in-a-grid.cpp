class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0,0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) return true;
            
            int val = grid[r][c];
            
            if (val ==2 || val == 5 || val == 6) {
                if (r - 1 >= 0 && !visited[r - 1][c]) {
                    int nval = grid[r - 1][c];
                    if (nval == 2 || nval == 3 || nval == 4) {
                        visited[r - 1][c] = true;
                        q.push({r - 1, c});
                    }
                }
            }
            
            if (val == 2 || val == 3 || val == 4) {
                if (r + 1 < m && !visited[r + 1][c]) {
                    int nval = grid[r + 1][c];
                    if (nval == 2 || nval == 5 || nval == 6) {
                        visited[r + 1][c] = true;
                        q.push({r + 1, c});
                    }
                }
            }
            
            if (val == 1 || val == 3 || val == 5) {
                if (c - 1 >= 0 && !visited[r][c - 1]) {
                    int nval = grid[r][c - 1];
                    if (nval == 1 || nval == 4 || nval == 6) {
                        visited[r][c - 1] = true;
                        q.push({r, c - 1});
                    }
                }
            }
            
            if (val == 1 || val == 4 || val == 6) {
                if (c + 1 < n && !visited[r][c + 1]) {
                    int nval = grid[r][c + 1];
                    if (nval == 1 || nval == 3 || nval == 5) {
                        visited[r][c + 1] = true;
                        q.push({r, c + 1});
                    }
                }
            }
        }
        
        return false;
    }
};