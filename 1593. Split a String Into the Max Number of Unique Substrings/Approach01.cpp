#include <string>
#include <unordered_set>

class Solution {
public:
    int maxUniqueSplit(std::string s) {
        size_t maxUniqueParts = 0;
        findMaxUniqueSplit(s, 0, {}, maxUniqueParts);
        return maxUniqueParts;
    }

private:
    void findMaxUniqueSplit(const std::string& str, int startIndex, std::unordered_set<std::string>&& uniqueSet, size_t& maxUniqueParts) {
        if (startIndex == str.length()) {
            maxUniqueParts = std::max(maxUniqueParts, uniqueSet.size());
            return;
        }

        for (int i = 1; startIndex + i <= str.length(); ++i) {
            const std::string currentPart = str.substr(startIndex, i);
            if (uniqueSet.find(currentPart) != uniqueSet.end())
                continue;
            uniqueSet.insert(currentPart);
            findMaxUniqueSplit(str, startIndex + i, std::move(uniqueSet), maxUniqueParts);
            uniqueSet.erase(currentPart);
        }
    }
};