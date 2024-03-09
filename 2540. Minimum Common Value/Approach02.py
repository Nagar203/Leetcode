from typing import *

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        i, j = 0, 0
        comman = []
        while(i<n1 and j<n2):
            if(nums1[i] == nums2[j]):
                comman.append(nums1[i])
                i += 1
                j += 1
            elif(nums1[i] < nums2[j]):
                i += 1
            else:
                j += 1
        if(len(comman) == 0):
            return -1
        result = min(comman)
        return result
