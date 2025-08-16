class Solution:
    def isPowerOfFour(self, number: int) -> bool:
        while number:
            if number == 1:
                return True
            if number % 4 != 0:
                return False
            number //= 4
        return False