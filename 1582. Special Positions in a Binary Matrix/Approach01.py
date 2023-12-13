from typing import *

class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        row = len(mat)
        col = len(mat[0])
        result = 0

        for i in range(row):
            for j in range(col):
                if(mat[i][j] == 1):
                    check_row = 0
                    check_col = 0
                    row_sum = 0
                    col_sum = 0

                    while(check_row < row):
                        col_sum += mat[check_row][j]
                        check_row += 1
                    while(check_col < col):
                        row_sum += mat[i][check_col]
                        check_col += 1

                    if(col_sum == 1 and row_sum == 1):
                        result += 1

        return result
