from typing import List

class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        resultXor = 0

        # If nums2 has an odd number of elements, XOR all elements of nums1
        if len(nums2) % 2 != 0:
            for num in nums1:
                resultXor ^= num

        # If nums1 has an odd number of elements, XOR all elements of nums2
        if len(nums1) % 2 != 0:
            for num in nums2:
                resultXor ^= num

        return resultXor