#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int minDeletions = 0;   // Minimum deletions to make the string balanced
        int countB = 0;         // Count of 'b's encountered so far

        for (const char c : s) {
            if (c == 'a') {
                // Either delete this 'a' or keep it and delete some 'b's seen before
                minDeletions = min(minDeletions + 1, countB);
            } else {
                ++countB;  // Increment count of 'b's
            }
        }

        return minDeletions;
    }
};
