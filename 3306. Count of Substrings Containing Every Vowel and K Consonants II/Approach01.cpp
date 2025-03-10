#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    long long countOfSubstrings(std::string word, int maxNonVowel) {
        return countSubstringsWithAtMost(word, maxNonVowel) - 
               countSubstringsWithAtMost(word, maxNonVowel - 1);
    }

private:
    long countSubstringsWithAtMost(const std::string& word, int maxNonVowel) {
        if (maxNonVowel == -1)
            return 0;

        long substringCount = 0;
        int vowelCount = 0;
        int uniqueVowelCount = 0;
        std::unordered_map<char, int> lastVowelPosition;

        for (int left = 0, right = 0; right < word.length(); ++right) {
            if (isVowel(word[right])) {
                ++vowelCount;
                if (const auto it = lastVowelPosition.find(word[right]); 
                    it == lastVowelPosition.end() || it->second < left)
                    ++uniqueVowelCount;
                lastVowelPosition[word[right]] = right;
            }

            while (right - left + 1 - vowelCount > maxNonVowel) {
                if (isVowel(word[left])) {
                    --vowelCount;
                    if (lastVowelPosition[word[left]] == left)
                        --uniqueVowelCount;
                }
                ++left;
            }

            if (uniqueVowelCount == 5) {
                substringCount += std::min({
                    lastVowelPosition['a'], lastVowelPosition['e'], 
                    lastVowelPosition['i'], lastVowelPosition['o'], 
                    lastVowelPosition['u']
                }) - left + 1;
            }
        }

        return substringCount;
    }

    bool isVowel(char character) {
        static constexpr std::string_view vowels = "aeiou";
        return vowels.find(character) != std::string_view::npos;
    }
};