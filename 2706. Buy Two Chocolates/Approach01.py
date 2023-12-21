from typing import *

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        result = money - (prices[0] + prices[1])
        return result if result >= 0 else money