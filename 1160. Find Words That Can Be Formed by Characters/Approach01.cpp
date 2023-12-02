#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<char, int> countCharacters(const string& s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        return charCount;
    }


    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charCount = countCharacters(chars);
        int result = 0;

        for (const string& word : words) {
            unordered_map<char, int> wordCount = countCharacters(word);
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