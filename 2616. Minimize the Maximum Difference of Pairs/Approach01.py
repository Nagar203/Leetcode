class Solution:
    def minimizeMax(self, nums: list[int], requiredPairs: int) -> int:
        nums.sort()
        low = 0
        high = nums[-1] - nums[0]

        while low < high:
            mid = (low + high) // 2
            if self.countValidPairs(nums, mid) >= requiredPairs:
                high = mid
            else:
                low = mid + 1
        return low

    def countValidPairs(self, nums: list[int], maxAllowedDiff: int) -> int:
        pairsFormed = 0
        i = 1
        while i < len(nums):
            if nums[i] - nums[i - 1] <= maxAllowedDiff:
                pairsFormed += 1
                i += 2
            else:
                i += 1
        return pairsFormed
