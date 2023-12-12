from typing import *

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n1, n2 = 0 , 0
        for num in nums:
            if(num > n1):
                n1, n2 = num, n1
            elif(num > n2):
                n2 = num
        return (n1-1)*(n2-1)