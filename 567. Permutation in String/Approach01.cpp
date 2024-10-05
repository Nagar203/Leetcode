#include <unordered_set>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string pattern, std::string text) {
        std::vector<int> charFrequency(26);
        int remainingChars = pattern.length();

        for (const char ch : pattern)
            ++charFrequency[ch - 'a'];

        for (int left = 0, right = 0; right < text.length(); ++right) {
            if (--charFrequency[text[right] - 'a'] >= 0)
                --remainingChars;

            while (remainingChars == 0) {
                if (right - left + 1 == pattern.length())
                    return true;
                if (++charFrequency[text[left++] - 'a'] > 0)
                    ++remainingChars;
            }
        }

        return false;
    }
};