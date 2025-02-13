#include <queue>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int target) {
        int operationCount = 0;
        std::priority_queue<long, std::vector<long>, std::greater<>> minHeap;

        // Insert all elements into the min-heap
        for (const int num : nums)
            minHeap.push(num);

        // Process elements while the smallest element is less than the target
        while (minHeap.size() > 1 && minHeap.top() < target) {
            int smallest = minHeap.top();
            minHeap.pop();
            int secondSmallest = minHeap.top();
            minHeap.pop();

            // Merge the two smallest elements and push back into the heap
            minHeap.push(std::min(smallest, secondSmallest) * 2L + std::max(smallest, secondSmallest));
            ++operationCount;
        }

        return operationCount;
    }
};