from typing import *

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        result = 0
        max_needed_time = neededTime[0]

        for i in range(1,len(colors)):
            if (colors[i] == colors[i - 1]):
                result += min(max_needed_time, neededTime[i])
                max_needed_time = max(max_needed_time, neededTime[i])
            else:
                max_needed_time = neededTime[i]
        return result;