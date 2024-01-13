#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        
        int freq[32] = {0};
        int n = s.length();

        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--; 
        }

        int result =0;

        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                result += freq[i];
            }
        }

        return result;

    }
};