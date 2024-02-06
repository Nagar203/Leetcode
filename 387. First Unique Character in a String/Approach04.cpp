#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(auto& ch: s){
            mp[ch]++;
        }
        int index = 0;
        for(auto& ch: s){
            if(mp[ch] == 1){
                return index; 
            }
            index++;
        }
        return -1;
    }
};
