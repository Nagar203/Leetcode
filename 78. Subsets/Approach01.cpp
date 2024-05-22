#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, 0, {}, result);
        return result;
    }

private:
    void solve(const vector<int>& nums, int s, vector<int>&& path, vector<vector<int>>& result) {
        result.push_back(path);

        for (int i = s; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            solve(nums, i + 1, move(path), result);
            path.pop_back();
        }
    }
};