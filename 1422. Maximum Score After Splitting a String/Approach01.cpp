#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string binaryString) {
        int stringLength = binaryString.length();
        int totalOnesInString = 0;  // Total number of '1's in the string
        
        // Count the total number of '1's in the string
        for (char character : binaryString) {
            if (character == '1') {
                ++totalOnesInString;
            }
        }

        int leftZeroCount = 0, rightOneCount = totalOnesInString, maximumScore = 0;
        
        // Iterate up to the second last character to ensure both parts are non-empty
        for (int index = 0; index < stringLength - 1; ++index) {
            if (binaryString[index] == '0') {
                ++leftZeroCount;
            } else {
                --rightOneCount;
            }

            // Calculate the score and update the maximum score
            maximumScore = max(maximumScore, leftZeroCount + rightOneCount);
        }

        return maximumScore;
    }
};