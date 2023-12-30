from typing import *
import sys

class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        
        t = [[-1 for _ in range(d + 1)] for _ in range(n)]

        max_data = -sys.maxsize - 1
        for i in range(n - 1, -1, -1):
            max_data = max(max_data, jobDifficulty[i])
            t[i][1] = max_data

        for days in range(2, d + 1):
            for i in range(n - days + 1):
                max_data = -sys.maxsize - 1
                result = sys.maxsize

                for j in range(i, n - days + 1):
                    max_data = max(max_data, jobDifficulty[j])
                    result = min(result, max_data + t[j + 1][days - 1])

                t[i][days] = result

        return t[0][d]