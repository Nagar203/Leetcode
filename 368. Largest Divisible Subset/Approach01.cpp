#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int totalNums = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> subsetLength(totalNums, 1);      // Length of divisible subset ending at each index
        vector<int> previousIndex(totalNums, -1);    // To reconstruct the subset
        vector<int> result;

        int maxSubsetEndIndex = 0;
        int maxSubsetLength = 1;

        for (int i = 1; i < totalNums; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && subsetLength[i] < subsetLength[j] + 1) {
                    subsetLength[i] = subsetLength[j] + 1;
                    previousIndex[i] = j;

                    if (subsetLength[i] > maxSubsetLength) {
                        maxSubsetLength = subsetLength[i];
                        maxSubsetEndIndex = i;
                    }
                }
            }
        }

        // Reconstruct the subset
        while (maxSubsetEndIndex != -1) {
            result.push_back(nums[maxSubsetEndIndex]);
            maxSubsetEndIndex = previousIndex[maxSubsetEndIndex];
        }

        return result;
    }
};