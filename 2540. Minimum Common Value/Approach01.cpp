#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        int result = INT_MAX;
        for(auto &it: nums1){
            s1.insert(it);
        }
        for(auto &it: nums2){
            if(s1.find(it) != s1.end()){
                result = min(result, it);
            }
        }
        if(result == INT_MAX){
            return -1;
        }
        return result;
    }
};