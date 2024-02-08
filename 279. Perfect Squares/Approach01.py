from typing import *

class Solution:
    def numSquares(self, n: int) -> int:

        def is_perfect_square(x):
            sqrt_x = int(x ** 0.5)
            return sqrt_x * sqrt_x == x

        if is_perfect_square(n):
            return 1

        while n % 4 == 0:
            n //= 4
        
        if n % 8 == 7:
            return 4

        for i in range(1, int(n ** 0.5) + 1):
            if is_perfect_square(n - i * i):
                return 2

        return 3
