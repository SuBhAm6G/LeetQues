class Solution {
public:
    string ans = "";
    int count = 0;

    void dfs(int n, int k, string &curr) {
        if(curr.size() == n) {
            count++;
            if(count == k) ans = curr;
            return;
        }

        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                dfs(n, k, curr);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        dfs(n, k, curr);
        return ans;
    }
};