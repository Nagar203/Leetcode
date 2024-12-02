class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int searchWordLength = searchWord.size();
        cout << searchWordLength << endl;

        vector<string> words;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        for (int wordIndex = 0; wordIndex < words.size(); ++wordIndex) {
            if (words[wordIndex].size() >= searchWordLength) {
                if (words[wordIndex].substr(0, searchWordLength) == searchWord) {
                    cout << words[wordIndex] << endl;
                    return wordIndex + 1;
                }
            }
        }
        return -1;
    }
};