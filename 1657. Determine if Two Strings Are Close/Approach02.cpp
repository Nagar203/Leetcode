#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1!=n2) return false;

        map<char, int> mp_1;
        map<char, int> mp_2;

        for(auto ch: word1){mp_1[ch]++;}
        for(auto ch: word2){mp_2[ch]++;}

        vector<char> key_1;
        vector<char> key_2;
        vector<int> value_1;
        vector<int> value_2;

        for(auto &it: mp_1){
            key_1.push_back(it.first);
            value_1.push_back(it.second);
        }

        for(auto &it: mp_2){
            key_2.push_back(it.first);
            value_2.push_back(it.second);
        }
        sort(value_1.begin(), value_1.end());
        sort(value_2.begin(), value_2.end());
        if(key_1 != key_2 || value_1 != value_2){
            return false;
        }

        return true;
    }
};