#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        vector<pair<int, char>> data;

        for(char &ch: s){
            mp[ch]++;
        }

        for(auto &it: mp){
            char char_val = it.first;
            int int_val = it.second;
            data.push_back({(-1)*int_val, char_val});
        }

        sort(data.begin(), data.end());
        string result = "";
        int data_len = data.size();

        for(int i=0; i < data_len; i++){
            int val = data[i].first;
            for(int j=0; j < (val*(-1)); j++){
                result += data[i].second;
            }
        }

        return result;

    }
};
