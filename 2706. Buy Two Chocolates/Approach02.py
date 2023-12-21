from typing import *
import sys

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        first_min = sys.maxsize
        second_min = sys.maxsize

        for i in range(len(prices)):
            if(prices[i] < first_min):
                second_min = first_min
                first_min = prices[i]
            elif(second_min > prices[i]):
                second_min = prices[i]

        result = money - (first_min + second_min)
        return result if result >=0 else money