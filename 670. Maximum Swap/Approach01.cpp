#include <unordered_set>
#include <vector>

class Solution {
public:
    int maximumSwap(int num) {
        string numString = to_string(num);
        vector<int> lastDigitIndex(10, -1);  // {digit: last index}

        // Record the last occurrence of each digit
        for (int i = 0; i < numString.length(); ++i)
            lastDigitIndex[numString[i] - '0'] = i;

        // Find the first opportunity to swap for maximum value
        for (int i = 0; i < numString.length(); ++i) {
            for (int d = 9; d > numString[i] - '0'; --d) {
                if (lastDigitIndex[d] > i) {
                    swap(numString[i], numString[lastDigitIndex[d]]);
                    return stoi(numString);
                }
            }
        }

        return num;  // Return the original number if no swap occurs
    }
};