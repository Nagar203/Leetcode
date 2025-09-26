class Solution:
    def triangleNumber(self, sideLengths: list[int]) -> int:
        if len(sideLengths) < 3:
            return 0

        validTriangleCount = 0
        sideLengths.sort()

        for largestIndex in range(len(sideLengths) - 1, 1, -1):
            leftIndex = 0
            rightIndex = largestIndex - 1

            while leftIndex < rightIndex:
                if sideLengths[leftIndex] + sideLengths[rightIndex] > sideLengths[largestIndex]:
                    validTriangleCount += rightIndex - leftIndex
                    rightIndex -= 1
                else:
                    leftIndex += 1

        return validTriangleCount