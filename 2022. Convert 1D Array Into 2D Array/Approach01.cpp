#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;

        // Check if the size of the original array matches the 2D array dimensions
        if (original.size() != m * n) {
            return {};  // Return an empty array if the sizes do not match
        }

        // Construct the 2D array
        for (int i = 0; i < m; i++) {
            vector<int> row(original.begin() + (i * n), original.begin() + (i + 1) * n);
            result.push_back(row);
        }

        return result;
    }
};