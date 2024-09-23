#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minExtraChar(const std::string& str, const std::vector<std::string>& wordList) {
        int stringLength = str.size();
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        std::vector<int> dpArray(stringLength + 1, 0);

        for (int i = 1; i <= stringLength; ++i) {
            dpArray[i] = dpArray[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                if (wordSet.count(str.substr(j, i - j))) {
                    dpArray[i] = std::min(dpArray[i], dpArray[j]);
                }
            }
        }

        return dpArray[stringLength];
    }
};