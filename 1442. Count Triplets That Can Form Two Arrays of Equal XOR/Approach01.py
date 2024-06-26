from typing import *


class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        result = 0
        xors = [0]
        prefix = 0

        for i, a in enumerate(arr):
            prefix ^= a
            xors.append(prefix)

        for j in range(1, len(arr)):
            for i in range(0, j):
                xors_i = xors[j] ^ xors[i]
                for k in range(j, len(arr)):
                    xors_k = xors[k + 1] ^ xors[j]
                    if xors_i == xors_k:
                        result += 1

        return result
