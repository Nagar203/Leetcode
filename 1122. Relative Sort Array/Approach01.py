from collections import Counter
from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        mp = Counter(arr1)
        result = []
        
        for d in arr2:
            if d in mp:
                result.extend([d] * mp[d])
                del mp[d] 

        for d in sorted(mp.elements()):
            result.append(d)
        
        return result
