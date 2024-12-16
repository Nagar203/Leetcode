import heapq

class Solution:
    def getFinalState(self, nums, k, multiplier):
        # Min-heap to store (value, index) pairs
        minHeap = [(val, idx) for idx, val in enumerate(nums)]
        heapq.heapify(minHeap)  # Convert the list to a min-heap

        # Perform k updates
        while k > 0:
            # Extract the minimum value and its index
            val, idx = heapq.heappop(minHeap)
            
            # Update the value and push it back into the heap
            val *= multiplier
            heapq.heappush(minHeap, (val, idx))
            k -= 1

        # Reconstruct the result array
        while minHeap:
            val, idx = heapq.heappop(minHeap)
            nums[idx] = val

        return nums