class Solution {
    int dist(int a, int b) {
        if (a == 26) return 0;
        return abs(a /6 - b /6) + abs(a %6 - b %6);
    }
    
public:
    int minimumDistance(string word) {
        vector<int> dp(27, 10000);
        dp[26] = 0;
        int prev = word[0] -'A';
        
        for (int i = 1; i < word.length(); ++i) {
            int target = word[i] - 'A';
            vector<int> next_dp(27, 10000);
            for (int c = 0; c <= 26; ++c) {
                if (dp[c] != 10000) {
                    next_dp[c] = min(next_dp[c], dp[c] + dist(prev, target));
                    next_dp[prev] = min(next_dp[prev], dp[c] + dist(c, target));
                }
            }
            dp = next_dp;
            prev = target;
        }
        
        int ans = 10000;
        for (int c = 0; c <= 26; ++c) {
            ans = min(ans, dp[c]);
        }
        
        return ans;
    }
};