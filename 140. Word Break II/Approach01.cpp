#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& word_dict) {
        unordered_set<string> word_set{word_dict.begin(), word_dict.end()};
        unordered_map<string, vector<string>> mem;
        return wordBreak(s, word_set, mem);
    }

private:
    vector<string> wordBreak(const string& s, const unordered_set<string>& word_set, unordered_map<string, vector<string>>& mem) {
        if (const auto it = mem.find(s); it != mem.cend())
            return it->second;

        vector<string> result;

        for (int i = 1; i < s.length(); ++i) {
            const string& prefix = s.substr(0, i);
            const string& suffix = s.substr(i);
            if (word_set.count(prefix))
                for (const string& word : wordBreak(suffix, word_set, mem))
                    result.push_back(prefix + " " + word);
        }

        if (word_set.count(s))
            result.push_back(s);

        return mem[s] = result;
    }
};