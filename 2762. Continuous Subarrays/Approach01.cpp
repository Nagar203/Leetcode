#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long result = 0; // Use long long for the result
        int left = 0; // Start of the current valid subarray

        deque<int> maxDeque; // Indices of potential maximum elements
        deque<int> minDeque; // Indices of potential minimum elements

        for (int right = 0; right < n; ++right) {
            // Maintain the maxDeque (decreasing order)
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Maintain the minDeque (increasing order)
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Check if the window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                // Shrink the window from the left
                if (maxDeque.front() == left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == left) {
                    minDeque.pop_front();
                }
                ++left;
            }

            // Add the number of valid subarrays ending at `right`
            result += (long long)(right - left + 1); // Explicitly cast to long long
        }

        return result;
    }
};