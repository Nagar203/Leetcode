class Solution:
    def maximum69Number(self, number: int) -> int:
        numberString = list(str(number))

        for i in range(len(numberString)):
            if numberString[i] == '6':
                numberString[i] = '9'
                break

        return int("".join(numberString))
