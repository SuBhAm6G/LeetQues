class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0;
        int currGroup = 1;
        int answer = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currGroup++;
            } else {
                answer += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        answer += min(prevGroup, currGroup);

        return answer;
    }
};
