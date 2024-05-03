#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = -1;
        for (int& v : nums) {
            if (s.count(-v)) {
                result = max(result, v);
            }
        }
        return result;
    }
};