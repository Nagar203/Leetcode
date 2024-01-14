#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        int freq_1[26] = {0};
        int freq_2[26] = {0};

        for (char s : word1) {freq_1[s-'a']++;}
        for (char s : word2) {freq_2[s-'a']++;}
       
                
        for (int i = 0; i < 26; i++) {
            if (freq_1[i] == 0 && freq_2[i] != 0) {
                return false;
            }
            if (freq_2[i] == 0 && freq_1[i] != 0) {
                return false;
            }
        }

        sort(freq_1, freq_1+26);
        sort(freq_2, freq_2+26);

        for(int i=0; i<26; i++){
            if(freq_1[i]!=freq_2[i]){
                return false;
            }
        }

        return true;
    }
};