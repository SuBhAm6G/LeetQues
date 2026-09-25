class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        n = len(expression)
        i = 0

        def multiply(a, b):
            return {x + y for x in a for y in b}

        def parse_concat():
            nonlocal i
            res = {""}

            while i < n and expression[i] not in "},":
                if expression[i].islower():
                    cur = {expression[i]}
                    i += 1
                else:
                    i += 1
                    cur = parse_union()
                    i += 1

                res = multiply(res, cur)

            return res

        def parse_union():
            nonlocal i
            res = set()

            while True:
                res |= parse_concat()

                if i < n and expression[i] == ',':
                    i += 1
                else:
                    break

            return res

        return sorted(parse_union())