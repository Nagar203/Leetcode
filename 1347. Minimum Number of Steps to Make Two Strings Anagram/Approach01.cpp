#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        
        int s_freq[32] = {0};
        int t_freq[32] = {0};
        int n = s.length();

        for(int i=0; i<n; i++){
            s_freq[s[i] - 'a']++;
            t_freq[t[i] - 'a']++; 
        }

        int result =0;

        for(int i=0; i<26; i++){
            if(s_freq[i] > t_freq[i]){
                result += (s_freq[i] - t_freq[i]);
            }
        }

        return result;

    }
};