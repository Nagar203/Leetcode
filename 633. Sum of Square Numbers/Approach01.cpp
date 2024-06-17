#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) {
            return true;
        }

        int limit = std::floor(sqrt(c));

        for (int i = 1; i <= limit; ++i) {
            int a = i * i;
            int data = c - a;
            int b = std::floor(sqrt(data));

            if ((a + b * b) == c) {
                return true;
            }
        }

        return false;
    }
};