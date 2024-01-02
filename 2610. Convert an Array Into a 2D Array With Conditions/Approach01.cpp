#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> count(nums.size() + 1);

    for (const int num : nums) {
      if (++count[num] > result.size()){
        result.push_back({});
      }
      result[count[num] - 1].push_back(num);
    }

    return result;
  }
};