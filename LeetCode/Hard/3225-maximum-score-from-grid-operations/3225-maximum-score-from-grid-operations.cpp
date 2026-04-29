class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;

        vector<vector<long long>> pref(n + 1, vector<long long>(n, 0));
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r < n; ++r) {
                pref[r + 1][c] = pref[r][c] + grid[r][c];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                long long score = 0;
                if (k > j) score = pref[k][0] - pref[j][0];
                dp[j][k] = score;
            }
        }

        for (int i = 2; i < n; ++i) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, 0));

            for (int j = 0; j <= n; ++j) {
                vector<long long> pref_max(n + 1, 0);
                pref_max[0] = dp[0][j];
                for (int p = 1; p <= n; ++p) {
                    pref_max[p] = max(pref_max[p - 1], dp[p][j]);
                }

                vector<long long> suff_max(n + 2, 0);
                suff_max[n + 1] = -1e15;
                for (int p = n; p >= 0; --p) {
                    long long score = pref[max(p, j)][i - 1] - pref[j][i - 1];
                    suff_max[p] = max(suff_max[p + 1], dp[p][j] + score);
                }

                for (int k = 0; k <= n; ++k) {
                    long long score_k = pref[max(k, j)][i - 1] - pref[j][i - 1];
                    long long op1 = pref_max[k] + score_k;
                    long long op2 = suff_max[k + 1];
                    next_dp[j][k] = max(op1, op2);
                }
            }
            dp = next_dp;
        }

        long long ans = 0;
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                long long score = 0;
                if (j > k) score = pref[j][n - 1] - pref[k][n - 1];
                ans = max(ans, dp[j][k] + score);
            }
        }

        return ans;
    }
};