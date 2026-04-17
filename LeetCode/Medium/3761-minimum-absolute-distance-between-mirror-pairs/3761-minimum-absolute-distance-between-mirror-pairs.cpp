#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int reverseInt(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev *10 + x %10;
            x /= 10;
        }
        return rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> expected_val_to_index;
        int min_dist =INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (expected_val_to_index.count(nums[i])) {
                int dist = i - expected_val_to_index[nums[i]];
                min_dist = min(min_dist, dist);
            }
            
            // Reverse the current number and store its index for future lookups
            int rev = reverseInt(nums[i]);
            expected_val_to_index[rev] = i;
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};