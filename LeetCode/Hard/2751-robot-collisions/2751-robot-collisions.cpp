class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });
        
        vector<int> st;
        for (int i : ids) {
            if (directions[i] == 'R') {
                st.push_back(i);
            } else {
                while (!st.empty() && directions[st.back()] == 'R' && healths[i] > 0) {
                    int top = st.back();
                    if (healths[i] > healths[top]) {
                        healths[i]--;
                        healths[top] = 0;
                        st.pop_back();
                    } else if (healths[i] < healths[top]) {
                        healths[top]--;
                        healths[i] = 0;
                    } else {
                        healths[i] = 0;
                        healths[top] = 0;
                        st.pop_back();
                    }
                }
                if (healths[i] > 0) {
                    st.push_back(i);
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        
        return ans;
    }
};