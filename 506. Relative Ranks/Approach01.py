from typing import *

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        data = score.copy()
        data.sort()
        data = data[::-1]
        mp = {}
        size = len(data)
        j = 0
        result = []

        for i in range(size):
            mp[data[j]] = i + 1 
            j += 1
        
        for d in score:
            val = mp[d]
            if val == 1:
                result.append("Gold Medal")
            elif val == 2:
                result.append("Silver Medal")
            elif val == 3:
                result.append("Bronze Medal")
            else:
                result.append(str(val))
   
        return result