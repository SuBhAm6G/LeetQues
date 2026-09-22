from typing import List


class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        n = len(nums)

        # Segment tree size
        size = 1
        while size < n:
            size <<= 1

        # prod[i] = product of the whole segment modulo k
        prod = [1] * (2 * size)

        # pref[i][r] = number of non-empty prefixes
        # of this segment having product % k == r
        pref = [[0] * k for _ in range(2 * size)]

        def merge(i: int):
            left = i << 1
            right = left | 1

            lp = pref[left]
            rp = pref[right]
            cur = pref[i]

            # Clear current node
            for r in range(k):
                cur[r] = lp[r]

            # Prefixes that cross from left into right
            left_prod = prod[left]

            for r in range(k):
                cur[(left_prod * r) % k] += rp[r]

            prod[i] = (left_prod * prod[right]) % k

        # Build leaves
        for i, val in enumerate(nums):
            p = val % k
            node = size + i

            prod[node] = p
            pref[node][p] = 1

        # Build tree
        for i in range(size - 1, 0, -1):
            merge(i)

        def update(pos: int, val: int):
            node = size + pos
            p = val % k

            prod[node] = p

            for r in range(k):
                pref[node][r] = 0
            pref[node][p] = 1

            node >>= 1
            while node:
                merge(node)
                node >>= 1

        def query(start: int) -> List[int]:
            # Returns aggregate information for [start, n-1]
            #
            # We use two accumulators because segment-tree traversal
            # can encounter pieces from both sides.

            left_prod = 1
            left_pref = [0] * k

            right_prod = 1
            right_pref = [0] * k

            l = start + size
            r = n + size

            while l < r:
                if l & 1:
                    # left accumulator + node l
                    node_prod = prod[l]
                    node_pref = pref[l]

                    new_pref = left_pref[:]
                    for rem in range(k):
                        new_pref[(left_prod * rem) % k] += node_pref[rem]

                    left_pref = new_pref
                    left_prod = (left_prod * node_prod) % k
                    l += 1

                if r & 1:
                    r -= 1

                    # node r + right accumulator
                    node_prod = prod[r]
                    node_pref = pref[r]

                    new_pref = node_pref[:]
                    for rem in range(k):
                        new_pref[(node_prod * rem) % k] += right_pref[rem]

                    right_pref = new_pref
                    right_prod = (node_prod * right_prod) % k

                l >>= 1
                r >>= 1

            # left part + right part
            result = left_pref[:]

            for rem in range(k):
                result[(left_prod * rem) % k] += right_pref[rem]

            return result

        ans = []

        for index, value, start, x in queries:
            update(index, value)
            ans.append(query(start)[x])

        return ans