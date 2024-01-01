#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int greed_len = g.size();
        int cookie_size = s.size();
        int i = 0, j = 0;

        while(i < greed_len && j < cookie_size){
            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};