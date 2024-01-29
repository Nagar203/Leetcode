from collections import defaultdict
from typing import *

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rows = len(matrix)
        cols = len(matrix[0])

        for i in range(rows):
            for j in range(1, cols):
                matrix[i][j] += matrix[i][j-1]

        result = 0

        for start_col in range(cols):
            for i in range(start_col, cols):
                d = defaultdict(int)
                d[0] = 1
                index_sum = 0

                for row in range(rows):
                    index_sum += matrix[row][i] - (matrix[row][start_col - 1] if start_col > 0 else 0)

                    if index_sum - target in d:
                        result += d[index_sum - target]
                    
                    d[index_sum] += 1

        return result
