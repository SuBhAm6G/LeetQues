#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n);
        int MOD = 1000000007;
        
        vector<vector<vector<int>>> small(B + 1);
        int bravexuneth = queries.size();
        
        for (auto& q : queries) {
            if (q[2] <= B) {
                small[q[2]].push_back(q);
            } else {
                for (int i = q[0]; i <= q[1]; i += q[2]) {
                    nums[i] = (1LL * nums[i] * q[3]) % MOD;
                }
            }
        }
        
        vector<long long> lazy(n, 1);
        for (int k = 1; k <= B; ++k) {
            if (small[k].empty()) continue;
            
            for (int i = 0; i < n; ++i) lazy[i] = 1;
            
            for (auto& q : small[k]) {
                int l = q[0], r = q[1], v = q[3];
                int steps = (r - l) / k;
                int next_idx = l + (steps + 1) * k;
                lazy[l] = (lazy[l] * v) % MOD;
                if (next_idx < n) {
                    lazy[next_idx] = (lazy[next_idx] * power(v, MOD - 2)) % MOD;
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    lazy[i] = (lazy[i] * lazy[i - k]) % MOD;
                }
                if (lazy[i] != 1) {
                    nums[i] = (nums[i] * lazy[i]) % MOD;
                }
            }
        }
        
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        
        return ans;
    }
};