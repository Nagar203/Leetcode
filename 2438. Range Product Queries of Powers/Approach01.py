class Solution:
    MOD = 10**9 + 7

    def productQueries(self, number: int, queryRanges: list[list[int]]) -> list[int]:
        powersOfTwo = []
        while number > 0:
            currentPower = number & -number
            powersOfTwo.append(currentPower)
            number -= currentPower

        results = []
        for startIndex, endIndex in queryRanges:
            product = 1
            for i in range(startIndex, endIndex + 1):
                product = (product * powersOfTwo[i]) % self.MOD
            results.append(product)

        return results
