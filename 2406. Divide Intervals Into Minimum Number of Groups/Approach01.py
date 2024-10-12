import heapq

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        # Stores the `endTimes` of intervals.
        endTimeMinHeap = []

        # Sort intervals by starting time.
        intervals.sort()

        for interval in intervals:
            # If there's no overlap, reuse the same group by removing the earliest ending interval.
            if endTimeMinHeap and interval[0] > endTimeMinHeap[0]:
                heapq.heappop(endTimeMinHeap)
            heapq.heappush(endTimeMinHeap, interval[1])

        # The size of the heap represents the number of groups required.
        return len(endTimeMinHeap)