#include <vector>
#include <algorithm>
#include <ranges>

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> result(nums.size());
        // Group numbers based on the difference condition <= limit
        vector<vector<pair<int, int>>> groupedNumbers;

        // Sort numbers with their indices
        for (const pair<int, int>& numAndIndex : getNumAndIndexes(nums)) {
            // Start a new group if the difference between num and the last number exceeds the limit
            if (groupedNumbers.empty() ||
                numAndIndex.first - groupedNumbers.back().back().first > limit) {
                groupedNumbers.push_back({numAndIndex});
            } else {
                // Append to the existing group
                groupedNumbers.back().push_back(numAndIndex);
            }
        }

        // Process each group of numbers
        for (const vector<pair<int, int>>& numAndIndexesGroup : groupedNumbers) {
            vector<int> sortedNums;
            vector<int> sortedIndices;
            for (const auto& [num, index] : numAndIndexesGroup) {
                sortedNums.push_back(num);
                sortedIndices.push_back(index);
            }
            std::ranges::sort(sortedIndices); // Sort indices to maintain the lexicographical order
            for (int i = 0; i < sortedNums.size(); ++i)
                result[sortedIndices[i]] = sortedNums[i]; // Assign sorted values to result
        }

        return result;
    }

private:
    vector<pair<int, int>> getNumAndIndexes(const vector<int>& nums) {
        vector<pair<int, int>> numAndIndexes;
        for (int i = 0; i < nums.size(); ++i)
            numAndIndexes.emplace_back(nums[i], i);
        std::ranges::sort(numAndIndexes); // Sort pairs based on the numbers
        return numAndIndexes;
    }
};
