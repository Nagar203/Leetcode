#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> data;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto &it: mp){
            data.push_back(it.second);
        }

        sort(data.begin(), data.end());
        int m = data.size();
        int remove = 0;
        
        for(int i=0; i<m; i++){
            if(k>=data[i]){
                k -= data[i];
                remove++;
            }
            else{
                return (m-remove);
            }
        }
        return 0;
    }
};