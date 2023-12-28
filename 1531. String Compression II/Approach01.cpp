#include <bits/stdc++.h>

using namespace std;

int t[101][27][101][101];

class Solution {
public:
    int solve(string &s, int i, int prev, int freq, int k) {
        if (k < 0)
            return INT_MAX;

        if (i >= s.length())
            return 0;

        if (t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }

        int delete_char = solve(s, i + 1, prev, freq, k - 1);

        int keep_char = 0;

        if (s[i] - 'a' == prev) {
            int one_addition = 0;
            if (freq == 1 || freq == 9 || freq == 99) {
                one_addition = 1;
            }
            keep_char = one_addition + solve(s, i + 1, prev, freq + 1, k);
        } else {
            keep_char = 1 + solve(s, i + 1, s[i] - 'a', 1, k);
        }

        return t[i][prev][freq][k] = min(delete_char, keep_char);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0, k);
    }
};