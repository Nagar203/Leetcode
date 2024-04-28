from typing import *

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = {}
        
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        
        values = [i for i in freq.values()]
        values.sort()
        
        data = values[-1]
        cnt = 0
        for val in values:
            if(data == val):
                cnt += val
            
        return cnt