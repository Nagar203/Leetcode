from typing import List
from collections import defaultdict

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        n = len(nums)
        count_map = defaultdict(int)
        result = []
        count_pairs = []
        
        for i in range(n):
            count_map[nums[i]] += 1

        for num, freq in count_map.items():
            count_pairs.append((freq, num))

        def compare(a, b):
            if a[0] != b[0]:
                return a[0] - b[0]
            else:
                return b[1] - a[1]

        count_pairs.sort(key=lambda x: (x[0], -x[1]))

        for freq, num in count_pairs:
            for _ in range(freq):
                result.append(num)

        return result