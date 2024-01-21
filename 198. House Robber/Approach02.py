from typing import *

class Solution:
    def __init__(self):
        self.t = [-1] * 101

    def solve(self, index, nums, n):
        if(n<=index):
            return 0
        
        if(self.t[index]!=-1):
            return self.t[index]

        rob = nums[index] + self.solve(index+2, nums, n)
        skip = self.solve(index+1, nums, n)

        self.t[index] = max(rob, skip)
        return self.t[index]