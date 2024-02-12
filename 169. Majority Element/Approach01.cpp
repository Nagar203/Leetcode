#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int check = n/2;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        int result = 0;
        for(auto &it: mp){
            if(it.second > check){
                result =  it.first;
            }
        }

        return result;
    }
};