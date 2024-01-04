#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> frequencyCounter;
        
        for (int num : nums) {
            frequencyCounter[num]++;
        }
        auto lambda = [](const auto& entry) { return entry.second == 1; };

        if (any_of(frequencyCounter.begin(), frequencyCounter.end(), lambda)) {
            return -1;
        }

        int result = 0;
        for (const auto& entry : frequencyCounter) {
            result += (entry.second + 2) / 3;
        }

        return result;
    }
};