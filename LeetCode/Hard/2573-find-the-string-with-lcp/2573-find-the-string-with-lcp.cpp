class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, 0);
        char c = 'a';
        
        for (int i = 0; i < n; ++i) {
            if (word[i] == 0) {
                if (c > 'z') return "";
                for (int j = i; j < n; ++j) {
                    if (lcp[i][j] > 0) {
                        word[j] = c;
                    }
                }
                c++;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int val = (word[i] == word[j]) ? 1 + ((i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] : 0) : 0;
                if (lcp[i][j] != val) {
                    return "";
                }
            }
        }
        
        return word;
    }
};