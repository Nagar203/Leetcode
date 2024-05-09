#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result = 0;
        int decremented = 0;

        ranges::sort(happiness, greater<>());

        for (int i = 0; i < k; ++i) {
            result += max(0, happiness[i] - decremented);
            ++decremented;
        }

        return result;
    }
};