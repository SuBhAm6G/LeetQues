class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        sign = -1 if x<0 else 1
        res = 0
        x = abs(x)
        while x>0:
            res = (res*10) + (x%10)
            x = x//10
        return sign*res if (sign*res < INT_MAX and sign*res > INT_MIN) else 0