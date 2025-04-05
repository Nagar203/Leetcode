class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def solve(i: int, xors: int) -> int:
            if i == len(nums):
                return xors

            x = solve(i + 1, xors)
            y = solve(i + 1, nums[i] ^ xors)
            return x + y

        return solve(0, 0)