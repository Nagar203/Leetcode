#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);
        for (const char c : letters){
            ++count[c - 'a'];
        }
        return solve(words, 0, count, score);
    }

private:
    int solve(const vector<string>& words, int s, vector<int>& count,
            const vector<int>& score) {
        int result = 0;
        for (int i = s; i < words.size(); ++i) {
            const int earned = use_word(words, i, count, score);
            if (earned > 0){
                result = max(result, earned + solve(words, i + 1, count, score));
            }
            un_use_word(words, i, count);
        }
        return result;
    }

    int use_word(const vector<string>& words, int i, vector<int>& count,
                const vector<int>& score) {
        bool is_valid = true;
        int earned = 0;
        for (const char c : words[i]) {
            if (--count[c - 'a'] < 0)
                is_valid = false;
            earned += score[c - 'a'];
        }
        return is_valid ? earned : -1;
    }

    void un_use_word(const vector<string>& words, int i, vector<int>& count) {
        for (const char c : words[i])
            ++count[c - 'a'];
    }
};