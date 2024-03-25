#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            ++mp[nums[i]];
            if(mp[nums[i]] == 2){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};