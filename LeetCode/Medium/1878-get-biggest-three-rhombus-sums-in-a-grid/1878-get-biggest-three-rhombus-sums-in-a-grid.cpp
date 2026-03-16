class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // radius = 0
                st.insert(grid[i][j]);

                for(int k = 1; ; k++){
                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n) break;

                    int sum = 0;

                    int x = i-k, y = j;

                    // top -> right
                    for(int t=0;t<k;t++){
                        sum += grid[x+t][y+t];
                    }

                    // right -> bottom
                    x = i; y = j+k;
                    for(int t=0;t<k;t++){
                        sum += grid[x+t][y-t];
                    }

                    // bottom -> left
                    x = i+k; y = j;
                    for(int t=0;t<k;t++){
                        sum += grid[x-t][y-t];
                    }

                    // left -> top
                    x = i; y = j-k;
                    for(int t=0;t<k;t++){
                        sum += grid[x-t][y+t];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for(auto it = st.rbegin(); it != st.rend() && ans.size() < 3; it++){
            ans.push_back(*it);
        }

        return ans;
    }
};