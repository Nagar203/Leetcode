#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        if(n%2 != 0){
            return -1;
        }

        string vowel = "aeiouAEIOU";
        int cnt_1=0, cnt_2 =0;

        for(int i=0; i<n/2; i++){
            if(vowel.find(s[i]) != -1){
                cnt_1++;
            }
            if(vowel.find(s[i+(n/2)]) != -1){
                cnt_2++;
            }
        }
        return cnt_1 == cnt_2;
    }
};