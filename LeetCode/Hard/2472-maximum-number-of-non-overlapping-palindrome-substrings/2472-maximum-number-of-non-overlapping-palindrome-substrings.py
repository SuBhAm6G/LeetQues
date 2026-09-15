class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        dp = [0] *(n + 1)
        ends = [[] for _ in range(n)]

        for c in range(n):
            l = r = c
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 >= k:
                    ends[r].append(l)
                l -=1
                r +=1

        for c in range(n - 1):
            l, r = c, c + 1
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 >= k:
                    ends[r].append(l)
                l -= 1
                r += 1

        for i in range(1, n + 1):
            dp[i] = dp[i - 1]
            for l in ends[i - 1]:
                dp[i] = max(dp[i],dp[l] + 1)

        return dp[n]