#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> sortedNums;
        vector<tuple<int, int, int>> mappedNums; // (mappedValue, originalIndex, originalValue)

        // Map each number to its corresponding value and store with its index
        // and original value
        for (int i = 0; i < nums.size(); ++i)
            mappedNums.emplace_back(getMappedValue(nums[i], mapping), i, nums[i]);

        // Sort the mapped numbers
        ranges::sort(mappedNums);

        // Collect the original numbers in sorted order
        for (const auto& [mappedValue, index, originalValue] : mappedNums)
            sortedNums.push_back(originalValue);

        return sortedNums;
    }

private:
    // Function to get the mapped value of a number based on the provided
    // mapping
    int getMappedValue(int num, const vector<int>& mapping) {
        string mappedString;
        for (const char c : to_string(num))
            mappedString += to_string(mapping[c - '0']);
        return stoi(mappedString);
    }
};
