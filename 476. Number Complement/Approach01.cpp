#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(long num) {
        for (long i = 1; i <= num; i <<= 1)
            num ^= i;
        return num;
    }
};