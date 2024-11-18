#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        // If k is 0, return an array of zeros
        if (k == 0) {
            return result;
        }

        // For positive k, sum the next k elements
        if (k > 0) {
            for (int i = 0; i < n; ++i) {
                int total = 0;
                for (int j = 1; j <= k; ++j) {
                    total += code[(i + j) % n];
                }
                result[i] = total;
            }
        } else {
            // For negative k, sum the previous k elements
            k = abs(k);
            for (int i = 0; i < n; ++i) {
                int total = 0;
                for (int j = 1; j <= k; ++j) {
                    total += code[(i - j + n) % n];
                }
                result[i] = total;
            }
        }

        return result;
    }
};