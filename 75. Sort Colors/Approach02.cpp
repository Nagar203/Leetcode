#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        int i = 0;
        int n = nums.size();

        for(int &n: nums){
          ++mp[n];
        }

        for(auto &it: mp){
            for(int j=0; j<it.second; j++){
              nums[i] = it.first;
              i++;
            }
        }
    }
};