#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long d = (long)(nums[i]) - nums[j];
                auto it = mp[j].find(d);
                int cnt = (it == mp[j].end()) ? 0 : it->second;
                mp[i][d] += cnt + 1;
                result += cnt;
            }
        }
        return result;
    }
};