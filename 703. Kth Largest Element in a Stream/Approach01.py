from typing import *
import heapq

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.kthLargest = k
        self.minHeap = []
        for num in nums:
            self.addElementToHeap(num)  # Add each element from the initial list to the heap.

    def add(self, value: int) -> int:
        self.addElementToHeap(value)
        return self.minHeap[0]  # The top of the min-heap is the kth largest element.

    def addElementToHeap(self, value: int):
        heapq.heappush(self.minHeap, value)  # Add the new element to the heap.
        if len(self.minHeap) > self.kthLargest:
            heapq.heappop(self.minHeap)  # Remove the smallest element if the heap exceeds size k.