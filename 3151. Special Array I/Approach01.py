class Solution:
    def isArraySpecial(self, nums: list[int]) -> bool:
        size = len(nums)

        if size == 1:
            return True

        for i in range(1, size):
            # Check if two consecutive numbers have the same parity
            if (nums[i] & 1) == (nums[i - 1] & 1):
                return False

        return True