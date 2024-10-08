#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string bracketString) {
        // Cancel out all the matched pairs, then we'll be left with "]]]..[[[".
        // The answer is ceil(the number of unmatched pairs / 2).
        int unmatchedOpenBrackets = 0;

        for (const char currentChar : bracketString) {
            if (currentChar == '[')
                ++unmatchedOpenBrackets;
            else if (unmatchedOpenBrackets > 0)  // currentChar == ']' and there's a match.
                --unmatchedOpenBrackets;
        }

        return (unmatchedOpenBrackets + 1) / 2;
    }
};
