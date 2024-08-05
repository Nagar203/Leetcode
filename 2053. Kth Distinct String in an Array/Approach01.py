from typing import List
from collections import Counter

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        frequencyMap = Counter(arr)

        # Iterate through the array to find the k-th distinct string
        for str in arr:
            if frequencyMap[str] == 1:
                k -= 1
                if k == 0:
                    return str  # Return the k-th distinct string

        return ""  # If there are fewer than k distinct strings, return an empty string
