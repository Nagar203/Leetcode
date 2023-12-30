#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int cnt[26] = {0};

        for(string &word: words){
            for(auto &ch: word){
                cnt[ch-'a']++;
            }
        }
        auto lambda = [&](int freq){
            return freq%n == 0;
        };
        return all_of(begin(cnt), end(cnt), lambda);
    }
};