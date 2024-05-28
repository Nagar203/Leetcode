#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int max_cost) {
        int j = 0;
        for (int i = 0; i < s.length(); ++i) {
            max_cost -= abs(s[i] - t[i]);
            if (max_cost < 0)
                max_cost += abs(s[j] - t[j++]);
        }

        return s.length() - j;
    }
};