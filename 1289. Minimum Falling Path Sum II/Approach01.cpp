#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();

        for (int i = 1; i < n; ++i) {
            const vector<pair<int, int>> two_min_num_and_indexs =
                solve(grid[i - 1]);
            const auto& [first_min_num, first_min_index] =
                two_min_num_and_indexs[0];
            const auto& [second_min_num, _] = two_min_num_and_indexs[1];
            for (int j = 0; j < n; ++j)
                if (j == first_min_index)
                    grid[i][j] += second_min_num;
                else
                    grid[i][j] += first_min_num;
        }

        return ranges::min(grid.back());
    }

private:
    vector<pair<int, int>> solve(const vector<int>& A) {
        vector<pair<int, int>> num_and_indexs;

        for (int i = 0; i < A.size(); ++i)
            num_and_indexs.emplace_back(A[i], i);

        ranges::sort(num_and_indexs);
        return {num_and_indexs[0], num_and_indexs[1]};
    }
};