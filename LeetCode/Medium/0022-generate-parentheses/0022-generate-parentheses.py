class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans = []
        path = [''] * (2 * n)

        def backtrack(pos, open_count, close_count):
            if pos == 2 * n:
                ans.append(''.join(path))
                return

            if open_count < n:
                path[pos] = '('
                backtrack(pos + 1, open_count + 1, close_count)

            if close_count < open_count:
                path[pos] = ')'
                backtrack(pos + 1, open_count, close_count + 1)

        backtrack(0, 0, 0)
        return ans