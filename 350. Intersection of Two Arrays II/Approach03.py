from typing import *

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:

        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)

        result = []
        lower_bound = 0  # lower bound for binary search

        # Sort both vectors for binary search
        nums1.sort()
        nums2.sort()

        for num in nums1:
            # Perform binary search on nums2 to find the target element (num)
            i = self.binary_search(nums2, lower_bound, num)
            if i < len(nums2) and nums2[i] == num:
                result.append(num)
                lower_bound = i + 1  # Update lower bound to avoid duplicates

        return result

    def binary_search(self, nums2, l, target):
        r = len(nums2)  # Upper bound (exclusive)
        while l < r:
            m = (l + r) // 2
            if nums2[m] >= target:
                r = m
            else:
                l = m + 1
        return l