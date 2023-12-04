from typing import List

class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        maxValue = 0
        result = ""

        for i in range(n - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                new_max = int(num[i])

                if new_max >= maxValue:
                    maxValue = new_max
                    result = num[i:i + 3]

        return result