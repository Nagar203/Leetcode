#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1)
            return 1;
        
        vector<int> first;
        vector<int> second;
        
        for (const auto& nums : trust) {
            first.push_back(nums[0]);
            second.push_back(nums[1]);
        }
        
        unordered_map<int, int> f;
        for (int s : second)
            f[s]++;
        
        for (auto& pair : f) {
            if ((n - 1) <= pair.second && pair.second <= n) {
                if (find(first.begin(), first.end(), pair.first) == first.end())
                    return pair.first;
            }
        }
        
        return -1;
    }
};