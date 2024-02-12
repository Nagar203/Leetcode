#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int check = n/2;
        int result = 0;
        unordered_map<int, int> mp;
        unordered_set<int> num;

        for(auto &it: nums){
            num.insert(it);
            mp[it]++;
        }

        for(auto &it: num){
            if(mp[it]>check){
                result = it;
            }
        }
        
        return result;
    }
};