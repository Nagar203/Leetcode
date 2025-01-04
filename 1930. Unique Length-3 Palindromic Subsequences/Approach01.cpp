#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string inputString) {
        int stringLength = inputString.size();
        int palindromicCount = 0;

        // Return 0 if the string has fewer than 3 characters
        if (stringLength < 3) {
            return palindromicCount;
        }

        // Iterate over each possible middle character
        for (int middleIndex = 0; middleIndex < 26; ++middleIndex) {
            char middleChar = 'a' + middleIndex;  // Map index to character
            size_t leftIndex = inputString.find(middleChar);  // First occurrence of middleChar
            size_t rightIndex = inputString.rfind(middleChar);  // Last occurrence of middleChar

            // Check if the character forms a valid palindrome structure
            if (leftIndex != string::npos && rightIndex != string::npos && leftIndex < rightIndex) {
                unordered_set<char> uniqueCharsBetween(
                    inputString.begin() + leftIndex + 1,
                    inputString.begin() + rightIndex
                );
                palindromicCount += uniqueCharsBetween.size();
            }
        }

        return palindromicCount;
    }
};