class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m = len(grid)
        n = len(grid[0])

        # Path length must be even for a valid parentheses string
        if (m + n - 1) % 2 != 0:
            return False

        dp = [[set() for _ in range(n)] for _ in range(m)]

        if grid[0][0] == ')':
            return False

        dp[0][0].add(1)

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                change = 1 if grid[i][j] == '(' else -1

                # From top
                if i > 0:
                    for balance in dp[i - 1][j]:
                        new_balance = balance + change
                        if new_balance >= 0:
                            dp[i][j].add(new_balance)

                # From left
                if j > 0:
                    for balance in dp[i][j - 1]:
                        new_balance = balance + change
                        if new_balance >= 0:
                            dp[i][j].add(new_balance)

        return 0 in dp[m - 1][n - 1]