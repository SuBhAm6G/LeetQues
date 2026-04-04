class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.size();
        int cols = n / rows;
        
        string res = "";
        
        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                res += encodedText[i * cols + j];
                i++;
                j++;
            }
        }
        
        while (!res.empty() && res.back() == ' ') res.pop_back();
        
        return res;
    }
};