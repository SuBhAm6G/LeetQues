class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int bitLength = 0;

        for (int i = 1; i <= n; i++) {
            // If i is a power of 2
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            // Shift left and add current number
            result = ((result << bitLength) + i) % MOD;
        }

        return result;
    }
};