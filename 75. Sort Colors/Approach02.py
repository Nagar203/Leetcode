from typing import List
from collections import defaultdict

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        mp = defaultdict(int)
        
        for num in nums:
            mp[num] += 1
        
        i = 0
        for key in sorted(mp.keys()):
            for _ in range(mp[key]):
                nums[i] = key
                i += 1
