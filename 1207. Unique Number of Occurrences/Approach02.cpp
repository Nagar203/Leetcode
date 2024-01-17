#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;

        for(auto &it: arr){
            mp[it]++;
        }
        int n = mp.size();

        set<int> s;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            s.insert(it->second);
        }

        int m = s.size();
        return n==m;
    }
};