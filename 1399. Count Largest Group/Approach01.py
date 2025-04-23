from typing import List
from collections import Counter

class Solution:
    def countLargestGroup(self, n: int) -> int:
        def calculate_digit_sum(num: int) -> int:
            s = 0
            while num:
                s += num % 10
                num //= 10
            return s

        groupSizes = Counter(calculate_digit_sum(i) for i in range(1, n + 1))
        maxSize = max(groupSizes.values())
        
        return sum(1 for size in groupSizes.values() if size == maxSize)