#include <string>
using namespace std;

class Solution {
public:
    string compressedString(const string& inputWord) {
        const int wordLength = inputWord.length();
        string compressedWord;

        for (int i = 0, j = 0; i < wordLength; i = j) {
            int count = 0;
            while (j < wordLength && inputWord[j] == inputWord[i] && count < 9) {
                ++j;
                ++count;
            }
            compressedWord += to_string(count) + inputWord[i];
        }

        return compressedWord;
    }
};
