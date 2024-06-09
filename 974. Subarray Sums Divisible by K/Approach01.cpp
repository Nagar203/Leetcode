#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        int prefix = 0;
        vector<int> count(k);
        count[0] = 1;

        for (const int num : nums) {
            prefix = (prefix + num % k + k) % k;
            result += count[prefix];
            ++count[prefix];
        }

        return result;
    }
};