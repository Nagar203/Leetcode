class Solution:
    def maxChunksToSorted(self, arr):
        chunksCount = 0
        maxElement = float('-inf')

        for currentIndex in range(len(arr)):
            maxElement = max(maxElement, arr[currentIndex])
            if maxElement == currentIndex:
                chunksCount += 1

        return chunksCount