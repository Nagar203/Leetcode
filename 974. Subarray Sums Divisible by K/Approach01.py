from typing import *

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        result = 0
        prefix = 0
        count = {0: 1}

        for num in nums:
            prefix = (prefix + num % k + k) % k  
            result += count.get(prefix, 0)
            count[prefix] = count.get(prefix, 0) + 1

        return result
