#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 != n2) return false;
        set<char> s1, s2;
        unordered_map<char, char> mp;
        
        for(int i=0; i<n1; i++){
            s1.insert(s[i]);
            s2.insert(t[i]);
            mp[s[i]] = t[i];
        }

        if(s1.size() != s2.size()) return false;

        for(int i=0; i<n1; i++){
            if(mp[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};