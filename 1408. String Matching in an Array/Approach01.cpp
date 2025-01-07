#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> substrings;  // Stores words that are substrings of other words

        for (const string& smallerWord : words) {
            for (const string& largerWord : words) {
                // Check if the smaller word is a substring of the larger word
                if (smallerWord.size() < largerWord.size() && largerWord.find(smallerWord) != string::npos) {
                    substrings.push_back(smallerWord);
                    break;  // No need to check further once found
                }
            }
        }

        return substrings;
    }
};