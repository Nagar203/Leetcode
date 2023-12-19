from typing import *

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        row = len(img)
        col = len(img[0])
        result = [[0]*col for _ in range(row)]

        direction= [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 0], [0, 1], [1, -1], [1, 0], [1, 1]]

        for i in range(row):
            for i in range(col):
                int sum = 0
                int count = 0

                for k in range(len(direction)):
                    int ni = i + direction[d][0]
                    int nj = j + direction[d][1]

                    if (ni >= 0 and ni < row and nj >= 0 and nj < col):
                        sum += img[ni][nj]
                        count += 1
                result[i][j] = sum // count
        return result
    
