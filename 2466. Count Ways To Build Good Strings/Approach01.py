class Solution:
    MOD = 10**9 + 7

    def solve(self, low, high, zero, one, currentLength):
        if currentLength > high:
            return 0

        # Memoization check
        if self.memo[currentLength] != -1:
            return self.memo[currentLength]

        # Base case: valid string within the range
        total = 0
        if low <= currentLength <= high:
            total = 1

        # Recursive case: add strings of zeros and ones
        left = self.solve(low, high, zero, one, currentLength + zero)
        right = self.solve(low, high, zero, one, currentLength + one)

        total = (total + left + right) % self.MOD
        self.memo[currentLength] = total  # Store result in memo
        return total

    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        # Initialize memoization table
        self.memo = [-1] * (high + 1)
        return self.solve(low, high, zero, one, 0)