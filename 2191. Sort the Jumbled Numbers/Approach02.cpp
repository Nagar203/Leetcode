#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> sortedNums;
        map<int, vector<int>> mappedToOriginalNums; // Map to store mapped value to original numbers

        // Map each number to its corresponding value and store in a map
        for (const int num : nums)
            mappedToOriginalNums[getMappedValue(num, mapping)].push_back(num);

        // Collect the original numbers in sorted order of their mapped values
        for (const auto& [mappedValue, originalNums] : mappedToOriginalNums)
            sortedNums.insert(sortedNums.end(), originalNums.begin(),
                              originalNums.end());

        return sortedNums;
    }

private:
    // Function to get the mapped value of a number based on the provided mapping
    int getMappedValue(int num, const vector<int>& mapping) {
        string mappedString;
        for (const char c : to_string(num))
            mappedString += to_string(mapping[c - '0']);
        return stoi(mappedString);
    }
};
