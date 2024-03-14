#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int result = 0;
        int cummu_sum = 0;

        mp[0] = 1;

        for (int& num : nums) {
            cummu_sum += num;
            int check = cummu_sum - goal;

            if (mp.find(check) != mp.end()) {
                result += mp[check];
            }

            mp[cummu_sum]++;
        }
        return result;
    }
};