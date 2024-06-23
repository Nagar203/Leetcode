from typing import *

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        n = len(strs)
        result = []
        final_result = []

        for i in range(n):
            num = [0]*26
            for ch in strs[i]:
                num[ord(ch) - ord('a')] += 1
            result.append(num)

        visited = []
        for i in range(n):
            temp = result[i]
            temp_list = []
            for j in range(i,n):
                if(temp == result[j] and (j not in visited)):
                    temp_list.append(strs[j])
                    visited.append(j)
            if(len(temp_list)!= 0):
                final_result.append(temp_list) 

        return final_result