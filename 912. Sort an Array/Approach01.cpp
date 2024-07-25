#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> countMap;  // Map to store the count of each number
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        // Count the occurrences of each number in the list
        for (const int num : nums) {
            countMap[num]++;
        }

        nums.clear();

        // Reconstruct the sorted list based on the countMap
        for (int value = minValue; value <= maxValue; ++value) {
            if (countMap.find(value) != countMap.end()) {
                nums.insert(nums.end(), countMap[value], value);
            }
        }

        return nums;
    }
};
