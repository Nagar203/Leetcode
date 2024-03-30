from collections import defaultdict

class Solution:
    def subarraysWithKDistinct(self, nums, k):
        n = len(nums)
        element_count = defaultdict(int)

        start_smallest = 0
        end = 0
        start_largest = 0

        result = 0

        while end < n:
            element_count[nums[end]] += 1

            while len(element_count) > k:
                element_count[nums[start_smallest]] -= 1
                if element_count[nums[start_smallest]] == 0:
                    del element_count[nums[start_smallest]]
                start_smallest += 1
                start_largest = start_smallest

            while element_count[nums[start_smallest]] > 1:
                element_count[nums[start_smallest]] -= 1
                start_smallest += 1

            if len(element_count) == k:
                result += start_smallest - start_largest + 1

            end += 1

        return result
