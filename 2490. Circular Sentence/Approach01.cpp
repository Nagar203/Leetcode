#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    bool isCircularSentence(const std::string& sentence) {
        std::vector<std::string> words;
        std::istringstream stream(sentence);
        std::string word;
        
        while (stream >> word) {
            words.push_back(word);
        }
        
        std::string firstLettersConcat;
        std::string shiftedLastLetters;
        
        for (const auto& w : words) {
            firstLettersConcat += w.front();
            shiftedLastLetters += w.back();
        }
        
        int sentenceLength = shiftedLastLetters.size();
        shiftedLastLetters = shiftedLastLetters.back() + shiftedLastLetters.substr(0, sentenceLength - 1);
        
        return shiftedLastLetters == firstLettersConcat;
    }
};