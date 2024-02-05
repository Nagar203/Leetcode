#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int result = INT_MAX;

        for(auto& ch: s){
            mp[ch]++;
        }

        for(auto &it: mp){
            if(it.second == 1){
                int index = s.find(it.first);
                result = min(result, index);
            }
        }
        return result==INT_MAX?-1: result;
    }
};
