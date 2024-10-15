#include <queue>
#include <vector>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& numbers, int k) {
        long long result = 0;  // Use long long for larger sums
        std::priority_queue<int> maxHeap(numbers.begin(), numbers.end());

        for (int i = 0; i < k; ++i) {
            int currentNumber = maxHeap.top();
            maxHeap.pop();
            result += currentNumber;
            // Push the next number (ceiling of currentNumber / 3) back into the heap
            maxHeap.push(static_cast<int>(std::ceil(currentNumber / 3.0)));
        }

        return result;
    }
};