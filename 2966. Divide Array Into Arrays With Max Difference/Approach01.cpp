#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;

        if (n % 3 != 0) {
            return {};
        }

        sort(nums.begin(), nums.end());

        int cnt = 0;
        for (int i = 0; i < n; i += 3) {
            result.emplace_back(vector<int>{nums[i], nums[i + 1], nums[i + 2]});
            cnt++;
            if((nums[i + 2] - nums[i] > k) || (nums[i + 1] - nums[i] > k) || (nums[i + 2] - nums[i+1] > k)){
                return {};
            }
        }

        return result;
    }
};
