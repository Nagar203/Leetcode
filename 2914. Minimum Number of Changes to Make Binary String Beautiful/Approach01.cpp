#include <string>
using namespace std;

class Solution {
public:
    int minChanges(const string& inputString) {
        int changeCount = 0;

        for (int index = 0; index + 1 < inputString.length(); index += 2) {
            if (inputString[index] != inputString[index + 1]) {
                ++changeCount;
            }
        }

        return changeCount;
    }
};