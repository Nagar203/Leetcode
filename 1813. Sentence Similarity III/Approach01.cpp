#include <unordered_set>
#include <vector>

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() == sentence2.length())
            return sentence1 == sentence2;

        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        const int size1 = words1.size();
        const int size2 = words2.size();
        
        if (size1 > size2)
            return areSentencesSimilar(sentence2, sentence1);

        int index = 0;  // words1's index
        while (index < size1 && words1[index] == words2[index])
            ++index;
        while (index < size1 && words1[index] == words2[index + size2 - size1])
            ++index;

        return index == size1;
    }

private:
    vector<string> split(const string& sentence) {
        vector<string> words;
        istringstream iss(sentence);

        for (string word; iss >> word;)
            words.push_back(word);

        return words;
    }
};