#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        const int n = nums.size(); // Size of the input vector
        const int totalOnes = ranges::count(nums, 1); // Total count of 1s in the input vector
        int currentOnesInWindow = 0; // The number of 1s in the current window
        int maxOnesInWindow = 0; // The maximum number of 1s in any window

        for (int i = 0; i < n * 2; ++i) {
            if (i >= totalOnes && nums[(i - totalOnes) % n])
                --currentOnesInWindow; // Remove the element that is sliding out of the window
            if (nums[i % n])
                ++currentOnesInWindow; // Add the new element sliding into the window
            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow); // Update the maximum number of 1s found in any window
        }

        return totalOnes - maxOnesInWindow; // Minimum swaps required is total 1s minus the maximum 1s in a window
    }
};
