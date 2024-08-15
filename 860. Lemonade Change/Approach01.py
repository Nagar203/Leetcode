from typing import *

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fiveDollarCount = 0
        tenDollarCount = 0

        for bill in bills:
            if bill == 5:
                fiveDollarCount += 1
            elif bill == 10:
                fiveDollarCount -= 1
                tenDollarCount += 1
            else:  # bill == 20
                if tenDollarCount > 0:
                    tenDollarCount -= 1
                    fiveDollarCount -= 1
                else:
                    fiveDollarCount -= 3

            if fiveDollarCount < 0:
                return False

        return True