#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;
        vector<pair<int, int>> s;
        
        for(int i=0; i<n; i++){
            ++mp[nums[i]];
        }

        for(auto &i: mp){
            s.push_back({i.second, i.first});
        }

        auto lambda = [](auto a, auto b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            else{
                return a.second < b.second;
            }
        };

        sort(s.rbegin(), s.rend(), lambda);

        for(auto &i: s){
            for(int j=0; j < i.first; j++){
                result.push_back(i.second);
            }
        }
        return result;
    }
};