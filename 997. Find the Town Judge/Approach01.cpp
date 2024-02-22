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
        
        for (int s : second) {
            int cnt = count(second.begin(), second.end(), s);
            if (find(first.begin(), first.end(), s) == first.end() && (n - 1) <= cnt && cnt <= n)
                return s;
        }
        
        return -1;
    }
};