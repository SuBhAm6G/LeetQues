class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0;
        long long right = 1e18;
        long long ans = right;

        while(left <= right)
        {
            long long mid = left + (right - left) / 2;

            long long reduced = 0;

            for(long long t : workerTimes)
            {
                long long val = (2 * mid) / t;
                long long x = (sqrt(1 + 4 * val) - 1) / 2;
                reduced += x;

                if(reduced >= mountainHeight)
                    break;
            }

            if(reduced >= mountainHeight)
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ans;
    }
};