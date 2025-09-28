class Solution:
    def largestPerimeter(self, sideLengths: list[int]) -> int:
        sideLengths.sort()

        for largestIndex in range(len(sideLengths) - 1, 1, -1):
            if sideLengths[largestIndex - 2] + sideLengths[largestIndex - 1] > sideLengths[largestIndex]:
                return sideLengths[largestIndex - 2] + sideLengths[largestIndex - 1] + sideLengths[largestIndex]

        return 0
