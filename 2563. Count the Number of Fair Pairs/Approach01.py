class Solution:
    def countFairPairs(self, nums: list[int], lower: int, upper: int) -> int:
        # Sort the array to use two-pointer approach
        nums.sort()

        def countLessThanOrEqual(maxSum: int) -> int:
            totalPairs = 0
            leftPointer = 0
            rightPointer = len(nums) - 1
            while leftPointer < rightPointer:
                while leftPointer < rightPointer and nums[leftPointer] + nums[rightPointer] > maxSum:
                    rightPointer -= 1
                totalPairs += rightPointer - leftPointer
                leftPointer += 1
            return totalPairs

        return countLessThanOrEqual(upper) - countLessThanOrEqual(lower - 1)
