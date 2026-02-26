class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            
            if (bit == 1) {
                // Odd case
                steps += 2; 
                carry = 1;
            } else {
                // Even case
                steps += 1;
            }
        }
        
        // If carry remains after processing MSB
        return steps - carry;
    }
};