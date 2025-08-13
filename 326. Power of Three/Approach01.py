class Solution:
    def isPowerOfThree(self, number: int) -> bool:
        if number <= 0:
            return False
            
        while number:
            if number == 1:
                return True
            if number % 3 != 0:
                return False
            number //= 3

        return True