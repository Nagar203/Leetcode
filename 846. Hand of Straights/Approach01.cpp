#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;

        for (const int card : hand) {
            ++mp[card];
        }

        for (const auto& [start, _] : mp) {
            const int value = mp[start];
            if (value > 0)
                for (int i = start; i < start + groupSize; ++i) {
                    mp[i] -= value;
                    if (mp[i] < 0) {
                        return false;
                    }
                }
        }

        return true;
    }
};