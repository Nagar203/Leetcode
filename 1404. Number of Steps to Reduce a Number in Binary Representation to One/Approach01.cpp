#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int result = 0;

        while (s.back() == '0') {
            s.pop_back();
            ++result;
        }

        if (s == "1")
            return result;

        ++result;
        for (const char c : s)
            result += c == '1' ? 1 : 2;

        return result;
    }
};