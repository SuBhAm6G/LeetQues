#include <vector>

class Fancy {
private:
    long long A;
    long long B;
    std::vector<long long> seq;
    const long long MOD = 1e9 + 7;

    // Fast exponentiation to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Modular inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        A = 1;
        B = 0;
    }
    
    void append(int val) {
        // Reverse the operation: X = (val - B) / A
        long long x = (val - B) % MOD;
        if (x < 0) x += MOD; // Handle negative modulo in C++
        
        x = (x * modInverse(A)) % MOD;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        B = (B + inc) % MOD;
    }
    
    void multAll(int m) {
        A = (A * m) % MOD;
        B = (B * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) {
            return -1;
        }
        
        long long val = (seq[idx] * A) % MOD;
        val = (val + B) % MOD;
        
        return val;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */