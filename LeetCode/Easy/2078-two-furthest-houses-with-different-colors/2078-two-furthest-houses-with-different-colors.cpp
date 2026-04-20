class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0, j = n - 1;
        while(colors[i]==colors[j]) j--;
        int x = abs(i - j);

        i = 0, j = n - 1;
        while(colors[i]==colors[j]) i++;
        int y = abs(i - j);

        return max(x,y);

    }
};