#include <unordered_set>
#include <vector>

class Solution {
public:
    int minAddToMakeValid(string parenthesesString) {
        int leftUnmatched = 0;
        int rightUnmatched = 0;

        for (const char currentChar : parenthesesString) {
            if (currentChar == '(') {
                ++leftUnmatched;
            } else {
                if (leftUnmatched == 0)
                    ++rightUnmatched;
                else
                    --leftUnmatched;
            }
        }

        return leftUnmatched + rightUnmatched;
    }
};