#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int targetSum = (rolls.size() + n) * mean;
        int missingSum = targetSum - accumulate(rolls.begin(), rolls.end(), 0);
        if (missingSum > n * 6 || missingSum < n){
            return {};
        }

        vector<int> result(n, missingSum / n);
        missingSum %= n;
        for (int i = 0; i < missingSum; ++i){
            ++result[i];
        }
        return result;
    }
};