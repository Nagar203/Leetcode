#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        array<int, 26> charCount = {};

        for (char c : chars) {
            charCount[c - 'a']++;
        }

        int result = 0;

        for (const string& word : words) {
            array<int, 26> wordCount = {};

            bool isGoodString = true;

            for (char c : word) {
                wordCount[c - 'a']++;
                if (wordCount[c - 'a'] > charCount[c - 'a']) {
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