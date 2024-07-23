from collections import Counter
from typing import List

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        count = Counter(nums)
        # Create a list of tuples (frequency, number)
        frequency_pairs = [(freq, num) for num, freq in count.items()]
        
        # Sort by frequency in ascending order, then by value in descending order
        frequency_pairs.sort(key=lambda x: (x[0], -x[1]))
        
        result = []
        for freq, num in frequency_pairs:
            result.extend([num] * freq)
        
        return result
