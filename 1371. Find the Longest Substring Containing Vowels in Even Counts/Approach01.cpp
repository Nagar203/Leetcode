#include <unordered_set>
#include <vector>

class Solution {
public:
    int findTheLongestSubstring(string s) {
        constexpr string_view vowels = "aeiou";
        int maxLength = 0;
        int binaryPrefix = 0;  // Binary representation of vowel counts
        unordered_map<int, int> prefixToIndex{{0, -1}};  // Stores the first occurrence of each binary prefix

        // Iterate through the string
        for (int i = 0; i < s.length(); ++i) {
            const int vowelIndex = vowels.find(s[i]);
            // If the current character is a vowel, update the binary prefix
            if (vowelIndex != -1) {
                binaryPrefix ^= 1 << vowelIndex;
            }
            // If the binary prefix hasn't been seen before, record its index
            if (!prefixToIndex.contains(binaryPrefix)) {
                prefixToIndex[binaryPrefix] = i;
            }
            // Calculate the length of the current substring
            maxLength = max(maxLength, i - prefixToIndex[binaryPrefix]);
        }

        return maxLength;
    }
};