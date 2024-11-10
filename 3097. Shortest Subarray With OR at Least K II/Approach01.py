class Solution:
    def minimumSubarrayLength(self, nums, targetOr):
        maxBits = 50
        n = len(nums)
        minLength = n + 1
        currentOrValue = 0
        bitCount = [0] * (maxBits + 1)

        left = 0
        right = 0
        while right < n:
            currentOrValue = self.orNum(currentOrValue, nums[right], bitCount)
            
            while currentOrValue >= targetOr and left <= right:
                minLength = min(minLength, right - left + 1)
                currentOrValue = self.undoOrNum(currentOrValue, nums[left], bitCount)
                left += 1
            
            right += 1

        return -1 if minLength == n + 1 else minLength

    maxBitPosition = 30

    # Function to compute OR value after including a new number
    def orNum(self, currentOrValue, num, bitCount):
        for i in range(self.maxBitPosition):
            if (num >> i) & 1:
                bitCount[i] += 1
                if bitCount[i] == 1:
                    currentOrValue += (1 << i)
        return currentOrValue

    # Function to adjust OR value after removing a number
    def undoOrNum(self, currentOrValue, num, bitCount):
        for i in range(self.maxBitPosition):
            if (num >> i) & 1:
                bitCount[i] -= 1
                if bitCount[i] == 0:
                    currentOrValue -= (1 << i)
        return currentOrValue