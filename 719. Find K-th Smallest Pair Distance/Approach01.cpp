#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the k-th smallest distance pair
    int smallestDistancePair(vector<int>& nums, int k) {
        ranges::sort(nums);

        int left = 0;
        int right = nums.back() - nums.front();

        // Binary search for the smallest distance
        while (left < right) {
            const int middle = (left + right) / 2;
            if (countPairsWithDistanceNoGreaterThan(nums, middle) >= k)
                right = middle;
            else
                left = middle + 1;
        }

        return left;
    }

private:
    // Function to count pairs with distance no greater than maxDistance
    int countPairsWithDistanceNoGreaterThan(const vector<int>& nums,
                                            int maxDistance) {
        int pairCount = 0;
        int j = 1;

        // For each index i, find the first index j such that nums[j] > nums[i] + maxDistance
        for (int i = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] <= nums[i] + maxDistance)
                ++j;
            pairCount += j - i - 1;
        }
        return pairCount;
    }
};