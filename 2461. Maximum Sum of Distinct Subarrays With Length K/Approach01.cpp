#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int subarraySize) {
    long maxSum = 0;
    long currentSum = 0;
    int uniqueCount = 0;
    unordered_map<int, int> frequencyMap;

    for (int i = 0; i < nums.size(); ++i) {
      currentSum += nums[i];

      if (++frequencyMap[nums[i]] == 1)  // New unique element
        ++uniqueCount;

      // Remove the element that is sliding out of the window
      if (i >= subarraySize) {
        if (--frequencyMap[nums[i - subarraySize]] == 0)
          --uniqueCount;
        currentSum -= nums[i - subarraySize];
      }

      // Check if the current subarray has exactly `subarraySize` unique elements
      if (i >= subarraySize - 1 && uniqueCount == subarraySize)
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
  }
};
