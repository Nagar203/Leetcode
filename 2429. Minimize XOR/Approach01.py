class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        setBitsInNum2 = bin(num2).count('1')
        minimizedResult = 0

        # Set bits in minimizedResult matching bits from num1, starting from MSB
        for bit in range(31, -1, -1):
            if setBitsInNum2 == 0:
                break
            if num1 & (1 << bit):
                minimizedResult |= (1 << bit)
                setBitsInNum2 -= 1

        # Set remaining bits from LSB to minimize the XOR value
        for bit in range(32):
            if setBitsInNum2 == 0:
                break
            if not (minimizedResult & (1 << bit)):
                minimizedResult |= (1 << bit)
                setBitsInNum2 -= 1

        return minimizedResult