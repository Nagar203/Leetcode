#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int result = -1;
        vector<int> cnt(26, -1);

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(cnt[ch - 'a'] == -1){
                cnt[ch-'a'] = i;
            }
            else{
                result = max(i - cnt[ch-'a'] -1, result);
            }
        }
        return result;
    }
};