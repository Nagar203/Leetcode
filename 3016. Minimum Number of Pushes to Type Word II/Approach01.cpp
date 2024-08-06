#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int wordLength = word.length();
        set<char> uniqueChars(word.begin(), word.end());
        int numUniqueChars = uniqueChars.size();
        unordered_map<char, int> charFrequency;
        
        // Calculate the frequency of each character in the word
        for (char ch : word) {
            charFrequency[ch]++;
        }

        // If there are 8 or fewer unique characters, return the total number of characters
        if (numUniqueChars <= 8) {
            int totalPushes = 0;
            for (const auto& entry : charFrequency) {
                totalPushes += entry.second;
            }
            return totalPushes;
        }

        int position = 1;
        int totalPushes = 0;
        
        // Get frequencies of characters sorted in descending order
        vector<int> sortedFrequencies;
        for (const auto& entry : charFrequency) {
            sortedFrequencies.push_back(entry.second);
        }
        sort(sortedFrequencies.rbegin(), sortedFrequencies.rend());
        
        // Calculate the total number of pushes based on the position of each character
        for (int frequency : sortedFrequencies) {
            if (position <= 8) {
                totalPushes += frequency;
            } else if (position <= 16) {
                totalPushes += frequency * 2;
            } else if (position <= 24) {
                totalPushes += frequency * 3;
            } else {
                totalPushes += frequency * 4;
            }
            position++;
        }

        return totalPushes;
    }
};