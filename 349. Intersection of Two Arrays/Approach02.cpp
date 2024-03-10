#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> result;
        for(auto &it: nums1){
            for(auto &i: nums2){
                if(i == it){
                    s.insert(it);
                }
            }
        }
        
        for(auto &it: s){
            result.push_back(it);
        }
        return result;
    }
};