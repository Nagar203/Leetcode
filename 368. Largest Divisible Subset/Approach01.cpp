#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> t(n, 1);
        vector<int> prev_index(n, -1);
        vector<int> result;

        int last_index = 0;
        int max_length = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(t[i] < t[j] + 1) {
                        t[i] = t[j] + 1;
                        prev_index[i] = j;
                    }
                    if(t[i] > max_length) {
                        max_length = t[i];
                        last_index = i;
                    }
                }
            }
        }
        while(last_index != -1) {
            result.push_back(nums[last_index]);
            last_index = prev_index[last_index];
        }
        return result;
    }
};