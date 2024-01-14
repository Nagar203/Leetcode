#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        set<char> set1(word1.begin(), word1.end());
        set<char> set2(word2.begin(), word2.end());

        if (set1 != set2) {
            return false;
        }

        unordered_map<char, int> freq_1, freq_2;

        for (char s : set1) {
            freq_1[s] = count(word1.begin(), word1.end(), s);
        }

        for (char s : set2) {
            freq_2[s] = count(word2.begin(), word2.end(), s);
        }

        vector<int> value_1, value_2;

        for (const auto& entry : freq_1) {
            value_1.push_back(entry.second);
        }

        for (const auto& entry : freq_2) {
            value_2.push_back(entry.second);
        }

        sort(value_1.begin(), value_1.end());
        sort(value_2.begin(), value_2.end());

        return value_1 == value_2;
    }
};