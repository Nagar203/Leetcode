class Solution:
    def minimumSize(self, nums: list[int], maxOperations: int) -> int:
        low = 1
        high = max(nums)

        while low < high:
            mid = (low + high) // 2
            if self.numOperations(nums, mid) <= maxOperations:
                high = mid
            else:
                low = mid + 1

        return low

    # Returns the number of operations required to make mid the penalty.
    def numOperations(self, nums: list[int], mid: int) -> int:
        totalOperations = 0
        for currentNum in nums:
            totalOperations += (currentNum - 1) // mid
        return totalOperations