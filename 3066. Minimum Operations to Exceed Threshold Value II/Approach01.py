import heapq

class Solution:
    def minOperations(self, nums, target):
        operationCount = 0
        minHeap = []

        # Insert all elements into the min-heap
        for num in nums:
            heapq.heappush(minHeap, num)

        # Process elements while the smallest element is less than the target
        while len(minHeap) > 1 and minHeap[0] < target:
            smallest = heapq.heappop(minHeap)
            secondSmallest = heapq.heappop(minHeap)

            # Merge the two smallest elements and push back into the heap
            heapq.heappush(minHeap, min(smallest, secondSmallest) * 2 + max(smallest, secondSmallest))
            operationCount += 1

        return operationCount