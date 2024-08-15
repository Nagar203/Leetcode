#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarCount = 0;
        int tenDollarCount = 0;

        for (const int bill : bills) {
            if (bill == 5) {
                ++fiveDollarCount;
            } else if (bill == 10) {
                --fiveDollarCount;
                ++tenDollarCount;
            } else { // bill == 20
                if (tenDollarCount > 0) {
                    --tenDollarCount;
                    --fiveDollarCount;
                } else {
                    fiveDollarCount -= 3;
                }
            }
            if (fiveDollarCount < 0)
                return false;
        }

        return true;
    }
};