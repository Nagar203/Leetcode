class Solution:
    def reorderedPowerOf2(self, number: int) -> bool:
        digitCountValue = self.getDigitCount(number)
        
        for bitShiftIndex in range(30):
            if self.getDigitCount(1 << bitShiftIndex) == digitCountValue:
                return True
        return False

    def getDigitCount(self, num: int) -> int:
        digitCountSum = 0
        while num > 0:
            digitCountSum += 10 ** (num % 10)
            num //= 10
        return digitCountSum