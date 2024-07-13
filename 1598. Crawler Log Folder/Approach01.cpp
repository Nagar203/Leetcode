#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;

        for (const string& log : logs) {
            if (log == "./")
                continue;
            if (log == "../")
                result = max(0, result - 1);
            else
                ++result;
        }

        return result;
    }
};