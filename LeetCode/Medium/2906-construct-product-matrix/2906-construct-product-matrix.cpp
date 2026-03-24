class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        int size = n * m;
        vector<int> arr(size);
        
        // Step 1: Flatten
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[idx++] = grid[i][j] % MOD;
            }
        }
        
        // Step 2: Prefix
        vector<int> prefix(size, 1);
        for(int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD;
        }
        
        // Step 3: Suffix
        vector<int> suffix(size, 1);
        for(int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % MOD;
        }
        
        // Step 4: Build result
        vector<vector<int>> result(n, vector<int>(m));
        idx = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = (prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }
        
        return result;
    }
};