#include <bits/stdc++.h>

using namespace std;

class Solution {
public: 
    int minSteps(string& s, string& t) {
        vector<int> freq(26, 0);

        for(char c: s) freq[c-'a']++;
        for(char c: t) freq[c-'a']--;

        int result=0;
        for_each(freq.begin(), freq.end(), [&](int data){result+=max(0, data);});
        return result;
    }
};