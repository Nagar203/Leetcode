#include <string>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(const string &sourceString, const string &targetString) {
        int targetIndex = 0; // Index for targetString

        for (char sourceChar : sourceString) {
            // Check if the current character matches or can rotate to match
            if (sourceChar == targetString[targetIndex] || 
                ('a' + (sourceChar - 'a' + 1) % 26) == targetString[targetIndex]) {
                targetIndex++;
                if (targetIndex == targetString.length())
                    return true;
            }
        }

        return false;
    }
};