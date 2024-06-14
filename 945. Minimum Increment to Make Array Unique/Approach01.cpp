#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int result = 0;
        int min_data = 0;

        ranges::sort(nums);

        for (const int num : nums) {
            result += max(min_data - num, 0);
            min_data = max(min_data, num) + 1;
        }

        return result;
    }
};