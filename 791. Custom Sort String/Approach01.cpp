#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char &ch: s){
            ++mp[ch];
        }
        string result, temp;
        for(auto &ch: order){
            if(mp.count(ch)>0){
                string sub_str(mp[ch],ch);
                result += sub_str;
            }
        }
        for(char &ch: s){
            char check = result.find(ch);
            if(check != string::npos){
                continue;
            }
            temp += ch;
        }
        
        return (result + temp);
    }
};