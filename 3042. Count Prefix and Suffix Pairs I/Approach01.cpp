#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if str1 is both a prefix and suffix of str2
    int isPrefixAndSuffix(string& prefixSuffixCandidate, string& targetString) {
        long long candidateLength = prefixSuffixCandidate.length();
        long long targetLength = targetString.length();

        // Extract the prefix and suffix from the target string
        string prefix = targetString.substr(0, candidateLength);
        string suffix = targetString.substr(targetLength - candidateLength, candidateLength);

        // Check if both the prefix and suffix match the candidate string
        if (prefix == prefixSuffixCandidate && suffix == prefixSuffixCandidate) {
            return 1;
        }
        return 0;
    }

    // Count all valid prefix-suffix pairs
    int countPrefixSuffixPairs(vector<string>& words) {
        long long totalWords = words.size();
        long long validPairCount = 0;

        // Iterate over all pairs of strings
        for (int i = 0; i < totalWords - 1; ++i) {
            for (int j = i + 1; j < totalWords; ++j) {
                // Check if the first word can be a prefix and suffix of the second word
                if (words[i].length() <= words[j].length()) {
                    validPairCount += isPrefixAndSuffix(words[i], words[j]);
                }
            }
        }

        return validPairCount;
    }
};