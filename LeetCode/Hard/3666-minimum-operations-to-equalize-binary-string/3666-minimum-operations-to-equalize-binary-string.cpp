#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function for ceiling division
    int ceil_div(int a, int b) {
        if (a == 0) return 0;
        return (a + b - 1) / b;
    }

public:
    int minOperations(string s, int k) {
        int n = s.length();
        int x = 0;
        
        for (char c : s) {
            if (c == '0') x++;
        }
        
        if (n == k) {
            if (x == 0) return 0;
            if (x == n) return 1;
            return -1;
        }
        
        if (k % 2 == 0 && x % 2 != 0) {
            return -1;
        }
        
        if (k % 2 != 0) {
            if (x % 2 == 0) {
                int M = max(ceil_div(x, k), ceil_div(x, n - k));
                if (M % 2 != 0) return M + 1;
                return M;
            } else {
                int M = max(ceil_div(x, k), ceil_div(n - x, n - k));
                if (M % 2 == 0) return M + 1;
                return M;
            }
        } else {
            int M0 = max(ceil_div(x, k), ceil_div(x, n - k));
            int even_m = (M0 % 2 != 0) ? M0 + 1 : M0;
            
            int M1 = max(ceil_div(x, k), ceil_div(n - x, n - k));
            int odd_m = (M1 % 2 == 0) ? M1 + 1 : M1;
            
            return min(even_m, odd_m);
        }
    }
};