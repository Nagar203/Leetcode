#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string currentSequence = "1";

        while (--n > 0) {
            string nextSequence;
            int i = 0;
            while (i < currentSequence.length()) {
                int count = 1;
                while (i + 1 < currentSequence.length() && currentSequence[i] == currentSequence[i + 1]) {
                    ++count;
                    ++i;
                }
                nextSequence += to_string(count) + currentSequence[i];
                ++i;
            }
            currentSequence = std::move(nextSequence);
        }

        return currentSequence;
    }
};
