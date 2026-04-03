class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> R(n);
        for (int i = 0; i < n; ++i) {
            R[i] = {robots[i], distance[i]};
        }
        sort(R.begin(), R.end());
        sort(walls.begin(), walls.end());

        int base_walls = 0;
        vector<int> filtered_walls;
        for (int w : walls) {
            auto it = lower_bound(R.begin(), R.end(), make_pair(w, -1));
            if (it != R.end() && it->first == w) {
                base_walls++;
            } else {
                filtered_walls.push_back(w);
            }
        }

        auto count = [&](int L, int R_val) {
            if (L > R_val) return 0;
            auto it1 = lower_bound(filtered_walls.begin(), filtered_walls.end(), L);
            auto it2 = upper_bound(filtered_walls.begin(), filtered_walls.end(), R_val);
            return max(0, (int)(it2 - it1));
        };

        int dp_L = count(R[0].first - R[0].second, R[0].first - 1);
        int dp_R = 0;

        for (int i = 1; i < n; ++i) {
            int P_prev = R[i-1].first;
            int D_prev = R[i-1].second;
            int P_curr = R[i].first;
            int D_curr = R[i].second;

            int r_reach = min(P_prev + D_prev, P_curr - 1);
            int l_reach = max(P_curr - D_curr, P_prev + 1);

            int cnt_R = count(P_prev + 1, r_reach);
            int cnt_L = count(l_reach, P_curr - 1);

            int intersection_L = max(P_prev + 1, l_reach);
            int intersection_R = min(P_curr - 1, r_reach);
            int cnt_intersect = 0;
            if (intersection_L <= intersection_R) {
                cnt_intersect = count(intersection_L, intersection_R);
            }
            int cnt_union = cnt_R + cnt_L - cnt_intersect;

            int new_dp_L = max(dp_L + cnt_L, dp_R + cnt_union);
            int new_dp_R = max(dp_L, dp_R + cnt_R);

            dp_L = new_dp_L;
            dp_R = new_dp_R;
        }

        int ans = max(dp_L, dp_R + count(R[n-1].first + 1, R[n-1].first + R[n-1].second));
        return ans + base_walls;
    }
};