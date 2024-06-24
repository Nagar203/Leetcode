#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips_needed = 0;
        int current_flips = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k && nums[i - k] == 2)
                --current_flips;
            if (current_flips % 2 == nums[i]) {
                if (i + k > nums.size())
                    return -1;
                ++flips_needed;
                ++current_flips;
                nums[i] = 2;
            }
        }

        return flips_needed;
    }
};
