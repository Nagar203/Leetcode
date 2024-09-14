#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = 0; // To store the maximum length of subarray
        int maxElementIndex = 0; // To track the index of the maximum element found
        int currentStreakLength = 0; // Length of the current streak of the maximum element

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == nums[maxElementIndex]) {
                maxLength = max(maxLength, ++currentStreakLength); // Update the max length
            } else if (nums[i] > nums[maxElementIndex]) {
                maxElementIndex = i; // Update the index of the new maximum element
                currentStreakLength = 1; // Reset the streak length to 1 for the new element
                maxLength = 1; // Reset the max length to 1
            } else {
                currentStreakLength = 0; // Reset the streak length if element is less than max
            }
        }

        return maxLength;
    }
};