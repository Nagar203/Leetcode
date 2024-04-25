#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> t(26);

        for (const char c : s) {
            const int i = c - 'a';
            t[i] = 1 + solve(t, i, k);
        }

        return ranges::max(t);
    }

private:
    int solve(const vector<int>& t, int i, int k) {
        const int first = max(0, i - k);
        const int last = min(25, i + k);
        int maxReachable = 0;
        for (int j = first; j <= last; ++j)
            maxReachable = max(maxReachable, t[j]);
        return maxReachable;
    }
};