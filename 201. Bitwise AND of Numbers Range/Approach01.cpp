#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        result = left << shift;
        return result;
    }
};