#include <unordered_set>
#include <vector>

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        for (auto &word : words) {
            int flag = 1;
            for (auto &ch : word) {
                if (allowed.find(ch) == -1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                result += 1;
            }
        }
        return result;
    }
};