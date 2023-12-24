from typing import *

class Solution:
    def minOperations(self, s: str) -> int:
        result1 = 0
        result2 = 0

        for i in range(len(s)):
            if(i%2 == 0 and s[i] != '0'):
                result1 +=1
            elif(i%2 != 0 and s[i] != '1'):
                result1 +=1
            
            if(i%2 == 0 and s[i] != '1'):
                result2 +=1
            elif(i%2 != 0 and s[i] != '0'):
                result2 +=1

        return min(result1, result2)

        
