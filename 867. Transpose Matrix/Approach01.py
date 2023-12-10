from typing import *

class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        row = len(matrix)
        col = len(matrix[0])

        result = [[0]*row for i in range(col)]


        for i in range(row):
            for j in range(col):
                result[j][i] = matrix[i][j];

        return result