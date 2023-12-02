#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }

        int result = 0;

        for (const string& word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }

            bool isGoodString = true;

            for (const auto& entry : wordCount) {
                if (entry.second > charCount[entry.first]) {
                    isGoodString = false;
                    break;
                }
            }

            if (isGoodString) {
                result += word.length();
            }
        }

        return result;
    }
};