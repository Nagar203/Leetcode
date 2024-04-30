#include <string>
#include <vector>

class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        long long result = 0;
        int prefix = 0;
        std::vector<int> count(1024, 0);
        count[0] = 1;

        for (char c : word) {
            prefix ^= 1 << (c - 'a');
            result += count[prefix];
            for (int i = 0; i < 10; ++i) {
                result += count[prefix ^ (1 << i)];
            }
            ++count[prefix];
        }

        return result;
    }
};
