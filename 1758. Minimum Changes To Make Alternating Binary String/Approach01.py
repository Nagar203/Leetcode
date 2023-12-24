from typing import *

class Solution:
    def minOperations(self, s: str) -> int:
        string1 = ''
        string2 = ''
        result1 = 0
        result2 = 0

        for i in range(len(s)):
            if(i%2 == 0):
                string1 = string1 + '0'
                string2 = string2 + '1'
            else:
                string1 = string1 + '1'
                string2 = string2 + '0'
        
        for i in range(len(s)):
            if(s[i] != string1[i]):
                result1 += 1
            if(s[i] != string2[i]):
                result2 += 1

        return min(result1, result2)