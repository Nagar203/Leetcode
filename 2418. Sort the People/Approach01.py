from typing import *

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        data = {}
        n = len(names)
        result = []

        for i in range(n):
            data[heights[i]] = names[i]
        
        heights.sort()
        heights = heights[::-1]
        for i in range(n):
            result.append(data[heights[i]])
        return result