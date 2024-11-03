#include <string>

class Solution {
public:
    bool rotateString(const std::string& original, const std::string& target) {
        if (original.length() != target.length()) {
            return false;
        }
        std::string doubledString = original + original;
        return doubledString.find(target) != std::string::npos;
    }
};