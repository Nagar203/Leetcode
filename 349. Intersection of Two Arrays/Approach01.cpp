#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        vector<int> result;

        for(auto &it: nums1){
            s1.insert(it);
        }
        for(auto &it: nums2){
            if(s1.find(it) != s1.end()){
                s2.insert(it);
            }
        }
        for(auto &it: s2){
            result.push_back(it);
        }
        return result;
    }
};