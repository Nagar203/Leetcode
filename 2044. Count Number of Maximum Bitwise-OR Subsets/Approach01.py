class Solution:
    def countMaxOrSubsets(self, nums: list[int]) -> int:
        maxOrValue = 0
        for num in nums:
            maxOrValue |= num  # Calculate the maximum OR value
        
        subsetCount = [0]  # Use a list to allow modification within dfs
        self.dfs(nums, 0, 0, maxOrValue, subsetCount)
        return subsetCount[0]  # Return the count stored in the list

    def dfs(self, nums: list[int], index: int, currentOrValue: int, maxOrValue: int, subsetCount: list[int]) -> None:
        if index == len(nums):
            if currentOrValue == maxOrValue:
                subsetCount[0] += 1  # Increment the count
            return

        # Exclude the current number
        self.dfs(nums, index + 1, currentOrValue, maxOrValue, subsetCount)

        # Include the current number
        self.dfs(nums, index + 1, currentOrValue | nums[index], maxOrValue, subsetCount)