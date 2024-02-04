#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t;
        int m = s.length();
        int n = t.length();

        if (n > m) {
            return "";
        }

        for(auto &ch: t){
            freq_t[ch]++;
        }

        int i = 0, j = 0;
        int required_cnt = n;
        int min_window_size = INT_MAX;
        int start_i = 0;

        while (j < m) {
            char ch = s[j];
            if (freq_t[ch] > 0) {
                required_cnt--;
            }
            freq_t[ch]--;
            while (required_cnt == 0) {
                int curr_window_size = j - i + 1;
                if (curr_window_size < min_window_size) {
                    min_window_size = curr_window_size;
                    start_i = i;
                }
                freq_t[s[i]]++;
                if (freq_t[s[i]] > 0) {
                    required_cnt++;
                }
                i++;
            }
            j++;
        }

        if (min_window_size == INT_MAX) {
            return "";
        }

        return s.substr(start_i, min_window_size);
    }
};