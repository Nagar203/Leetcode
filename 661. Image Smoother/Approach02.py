from typing import *

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        row = len(img)
        col = len(img[0])
        result = [[0]*col for _ in range(row)]
    
        if(row==1 and col ==1):
            return img
        
        for i in range(row):
            for j in range(col):
                if(col > 0  and row ==1):
                    if(j==0):
                        result[i][j] = (img[i][j] + img[i][j+1])//2                    
                    elif(j == col-1):
                        result[i][j] = (img[i][j] + img[i][j-1])//2                    
                    else:
                        result[i][j] = (img[i][j] + img[i][j-1] + img[i][j+1])//3
                    
                elif(row > 0  and col ==1):
                    if(i==0):
                        result[i][j] = (img[i][j] + img[i+1][j])//2                    
                    elif(i == row-1):
                        result[i][j] = (img[i][j] + img[i-1][j])//2                    
                    else:
                        result[i][j] = (img[i][j] + img[i-1][j] + img[i+1][j])//3
                
                elif((i > 0 and j > 0) and (i < (row-1) and j < (col-1))):
                    result[i][j] = (img[i][j] + img[i+1][j] + img[i-1][j] + img[i][j+1] + img[i][j-1] + img[i-1][j-1] + img[i+1][j-1] + img[i-1][j+1] + img[i+1][j+1])//9
                
                elif((i == 0 and j == 0) or (i == 0 and j == col-1) or (i == row-1 and j == 0) or (i == row-1 and j == col-1)):
                    if(i == 0 and j == 0):
                        result[i][j] = (img[i][j] + img[i+1][j] + img[i][j+1] + img[i+1][j+1])//4                    
                    elif(i == 0 and j == col-1):
                        result[i][j] = (img[i][j] + img[i+1][j] + img[i][j-1] + img[i+1][j-1])//4                    
                    elif(i == row-1 and j == 0):
                        result[i][j] = (img[i][j] + img[i-1][j] + img[i][j+1] + img[i-1][j+1])//4                    
                    elif(i == row-1 and j == col-1):
                        result[i][j] = (img[i][j] + img[i-1][j] + img[i][j-1] + img[i-1][j-1])//4
                
                elif( i > 0 and i < row-1 and j == 0):
                    result[i][j] = (img[i][j] + img[i-1][j] + img[i][j+1] + img[i-1][j+1] + img[i+1][j] + img[i+1][j+1])//6                
                elif( i > 0 and i < row-1 and j == col-1):
                    result[i][j] = (img[i][j] + img[i-1][j] + img[i][j-1] + img[i-1][j-1] + img[i+1][j] + img[i+1][j-1])//6
                elif( j > 0 and j < col-1 and i == 0):
                    result[i][j] = (img[i][j] + img[i+1][j] + img[i][j+1] + img[i+1][j+1] + img[i+1][j-1] + img[i][j-1])//6
                elif( j > 0 and j < col-1 and (i == row-1)):
                    result[i][j] = (img[i][j] + img[i][j+1] + img[i][j-1] + img[i-1][j-1] + img[i-1][j+1] + img[i-1][j])//6             
        
        return result
    
