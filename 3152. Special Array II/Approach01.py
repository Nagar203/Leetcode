class Solution:
    def isArraySpecial(self, nums: list[int], queries: list[list[int]]) -> list[bool]:
        results = []
        parityGroupId = 0
        # parityGroupIds[i] := the group ID of the parity that nums[i] belongs to
        parityGroupIds = [parityGroupId]

        for i in range(1, len(nums)):
            if nums[i] % 2 == nums[i - 1] % 2:
                parityGroupId += 1
            parityGroupIds.append(parityGroupId)

        for query in queries:
            startIndex = query[0]
            endIndex = query[1]
            results.append(parityGroupIds[startIndex] == parityGroupIds[endIndex])

        return results