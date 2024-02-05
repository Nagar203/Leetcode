#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int data[26] = {0};
        int n = s.size();
        int result = INT_MAX;

        for(auto& ch: s){
            data[ch - 'a']++;
        }

        for(int i=0; i < 26; i++){
            if(data[i] == 1){
                int index = s.find(char(i + 'a'));
                result = min(result, index);
            }
        }
        return result==INT_MAX?-1: result;
    }
};
