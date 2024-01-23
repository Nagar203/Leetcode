#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result = 0;
        vector<int> cover = {0};
        for (auto& s : arr) {
            int mask = 0;
            for (auto& c : s) {
                int i = c - 'a';
                if (mask >> i & 1) {
                    mask = 0;
                    break;
                }
                mask |= 1 << i;
            }
            if (mask == 0) {
                continue;
            }
            int n = cover.size();
            for (int i = 0; i < n; ++i) {
                int m = cover[i];
                if ((m & mask) == 0) {
                    cover.push_back(m | mask);
                    result = max(result, __builtin_popcount(m | mask));
                }
            }
        }
        return result;
    }
};