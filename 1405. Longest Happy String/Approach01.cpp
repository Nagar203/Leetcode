#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestDiverseString(int countA, int countB, int countC, char charA = 'a', char charB = 'b', char charC = 'c') {
        if (countA < countB)
            return longestDiverseString(countB, countA, countC, charB, charA, charC);
        if (countB < countC)
            return longestDiverseString(countA, countC, countB, charA, charC, charB);
        if (countB == 0)
            return std::string(std::min(countA, 2), charA);

        int useCharA = std::min(countA, 2);
        int useCharB = (countA - useCharA >= countB) ? 1 : 0;

        return std::string(useCharA, charA) + std::string(useCharB, charB) +
               longestDiverseString(countA - useCharA, countB - useCharB, countC, charA, charB, charC);
    }
};