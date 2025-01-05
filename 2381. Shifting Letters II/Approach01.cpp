#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int accumulatedShift = 0;  // Accumulated shift at each position
        vector<int> shiftDifferences(s.length() + 1, 0);  // Timeline of shifts

        // Apply shifts to the timeline
        for (const vector<int>& shift : shifts) {
            const int startIdx = shift[0];  // Starting index for the shift
            const int endIdx = shift[1];    // Ending index for the shift
            const int direction = shift[2];  // Direction of the shift (1 for right, 0 for left)
            const int shiftValue = direction ? 1 : -1;  // +1 for right shift, -1 for left shift
            shiftDifferences[startIdx] += shiftValue;
            shiftDifferences[endIdx + 1] -= shiftValue;
        }

        // Apply the accumulated shifts to the string
        for (int i = 0; i < s.length(); ++i) {
            accumulatedShift = (accumulatedShift + shiftDifferences[i]) % 26;
            const int newCharPos = (s[i] - 'a' + accumulatedShift + 26) % 26;
            s[i] = 'a' + newCharPos;
        }

        return s;
    }
};
