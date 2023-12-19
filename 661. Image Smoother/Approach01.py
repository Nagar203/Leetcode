from typing import *

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        row = len(img)
        col = len(img[0])
        result = [[0]*col for _ in range(row)]

        direction= [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 0], [0, 1], [1, -1], [1, 0], [1, 1]]

        for i in range(row):
            for j in range(col):
                sum = 0
                count = 0

                for k in range(len(direction)):
                    ni = i + direction[k][0]
                    nj = j + direction[k][1]

                    if (ni >= 0 and ni < row and nj >= 0 and nj < col):
                        sum += img[ni][nj]
                        count += 1
                result[i][j] = sum // count
        return result
    
