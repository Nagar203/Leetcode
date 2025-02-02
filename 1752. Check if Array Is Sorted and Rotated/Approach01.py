class Solution:
    def check(self, nums: list[int]) -> bool:
        size = len(nums)
        rotation_count = 0

        for i in range(size):
            if nums[i] > nums[(i + 1) % size]:
                rotation_count += 1
                if rotation_count > 1:
                    return False

        return True
