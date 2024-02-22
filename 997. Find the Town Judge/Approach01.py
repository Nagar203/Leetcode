from typing import *

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if(len(trust)==0 and n==1):
            return 1
        first = []
        second = []

        for nums in trust:
            first.append(nums[0])
            second.append(nums[1])
        for s in second:
            cnt = second.count(s)
            if s not in first and ((n-1)<= cnt <=n):
                return s
        return -1