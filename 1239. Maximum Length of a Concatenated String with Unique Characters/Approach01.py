from typing import *

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        result = 0
        cover = [0]

        for s in arr: #s=bcd
            mask = 0
            for c in s:
                i = ord(c) - ord('a') # i = 1
                if mask >> i & 1:
                    mask = 0
                    break
                mask |= 1 << i
            if mask == 0:
                continue
            for m in cover:
                if m & mask == 0:
                    cover.append(m | mask)
                    result = max(result, (m | mask).bit_count())
        return result