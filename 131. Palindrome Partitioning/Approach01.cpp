#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        solve(s, 0, {}, result);
        return result;
    }

private:
    void solve(const string& s, int start, vector<string>&& path,
             vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); ++i)
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                solve(s, i + 1, move(path), result);
                path.pop_back();
            }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};