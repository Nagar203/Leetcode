#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long max_sum = 0;
        int changedCount = 0;
        int min_change_diff = INT_MAX;

        for (const int num : nums) {
            max_sum += max(num, num ^ k);
            changedCount += ((num ^ k) > num) ? 1 : 0;
            min_change_diff = min(min_change_diff, abs(num - (num ^ k)));
        }

        if (changedCount % 2 == 0)
            return max_sum;
        return max_sum - min_change_diff;
    }
};