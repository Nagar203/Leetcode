#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        string s = "";
        for(int i=0; i<n; i++){
            s += words[i]; 
        }
        int str_len = s.size();
        map<char, int> mp;
        
        for(int i=0; i <str_len; i++){
            ++mp[s[i]];
        }
        for(auto i:mp){
            if(i.second%n != 0){
                return false;
            }
        }
        return true;
    }
};