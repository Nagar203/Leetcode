#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string addSpaces(const std::string &inputString, const std::vector<int> &spaces) {
        int charIndex = 0;
        std::string resultString;
        std::unordered_map<int, int> spaceMap;

        for (int spaceIndex : spaces) {
            spaceMap[spaceIndex]++;
        }

        for (char character : inputString) {
            if (spaceMap[charIndex] > 0) {
                resultString += ' ';
            }
            resultString += character;
            charIndex++;
        }

        return resultString;
    }
};