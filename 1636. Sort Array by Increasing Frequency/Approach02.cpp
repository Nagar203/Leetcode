#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<pair<int, int>> frequency_pairs;
        
        // Count the frequency of each number
        for (int num : nums) {
            count[num]++;
        }

        // Create a list of pairs (frequency, number)
        for (auto& it : count) {
            frequency_pairs.push_back({it.second, it.first});
        }

        // Sort by frequency in ascending order, then by value in descending order
        sort(frequency_pairs.begin(), frequency_pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second; // Sort by value in descending order
            return a.first < b.first; // Sort by frequency in ascending order
        });

        vector<int> result;
        for (auto& p : frequency_pairs) {
            result.insert(result.end(), p.first, p.second);
        }

        return result;
    }
};