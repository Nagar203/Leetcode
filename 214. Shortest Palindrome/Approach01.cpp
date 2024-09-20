#include <unordered_set>
#include <vector>

class Solution {
public:
    string shortestPalindrome(string inputString) {
        const string reversedString = {inputString.rbegin(), inputString.rend()};
        const string_view originalView(inputString);
        const string_view reversedView(reversedString);

        // Check the longest palindromic prefix
        for (int i = 0; i < inputString.length(); ++i) {
            if (originalView.substr(0, inputString.length() - i) == reversedView.substr(i)) {
                return reversedString.substr(0, i) + inputString;
            }
        }

        return reversedString + inputString;
    }
};