class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a); //returns number of 1's in binary form.
            int bitsB = __builtin_popcount(b);
            
            if (bitsA == bitsB)
                return a < b;
            
            return bitsA < bitsB;
        });
        
        return arr;
    }
};