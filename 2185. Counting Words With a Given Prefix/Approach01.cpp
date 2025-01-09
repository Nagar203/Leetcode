#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string prefix) {
        int wordCount = words.size();  // Number of words in the input
        int prefixLength = prefix.length();  // Length of the prefix
        int matchingCount = 0;  // Counter for words starting with the prefix
        
        for (int i = 0; i < wordCount; ++i) {
            if (words[i].length() >= prefixLength) {  // Ensure the word is at least as long as the prefix
                string wordPrefix = words[i].substr(0, prefixLength);  // Extract the prefix from the word
                if (wordPrefix == prefix) {  // Check if the prefix matches
                    ++matchingCount;
                }
            }
        }
        
        return matchingCount;  // Return the total count of matching words
    }
};