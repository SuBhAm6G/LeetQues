class Solution {
    struct DSU {
        vector<int> parent;
        int comps;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            comps = n;
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                comps--;
                return true;
            }
            return false;
        }
    };

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int min_must = 2e9;
        DSU base_dsu(n);
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!base_dsu.unite(e[0], e[1])) {
                    return -1;
                }
                min_must = min(min_must, e[2]);
            }
        }

        DSU full_dsu = base_dsu;
        for (const auto& e : edges) {
            if (e[3] == 0) {
                full_dsu.unite(e[0], e[1]);
            }
        }
        
        if (full_dsu.comps > 1) {
            return -1;
        }

        int low = 1, high = 200000;
        if (min_must != 2e9) {
            high = min(high, min_must);
        }
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            DSU dsu = base_dsu;
            int cost = 0;

            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] >= mid) {
                    dsu.unite(e[0], e[1]);
                }
            }

            for (const auto& e : edges) {
                if (e[3] == 0 && e[2] < mid && e[2] * 2 >= mid) {
                    if (dsu.unite(e[0], e[1])) {
                        cost++;
                    }
                }
            }

            if (dsu.comps == 1 && cost <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};