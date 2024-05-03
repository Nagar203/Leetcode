#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &num: nums){
            mp[num]++;
        }
        int temp = -1;
        for(auto &it: mp){
            temp = max(temp, it.second);
        }
        int result = 0;
        for(auto &it: mp){
            if(temp == it.second){
                result += it.second;
            }
        }
        return result;
    }
};