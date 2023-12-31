#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int result = -1;
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(mp.find(ch) == mp.end()){
                mp[s[i]] = i;
            }
            else{
                result = max(i - mp[ch] -1, result);
            }
        }
        return result;
    }
};