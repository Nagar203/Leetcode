#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const vector<vector<int>> dist_to_thief = getdist_to_thief(grid);
        int l = 0;
        int r = grid.size() * 2;

        while (l < r) {
            const int m = (l + r) / 2;
            if (hasValidPath(dist_to_thief, m))
                l = m + 1;
            else
                r = m;
        }

        return l - 1;
    }

private:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool hasValidPath(const vector<vector<int>>& dist_to_thief, int safeness) {
        if (dist_to_thief[0][0] < safeness)
            return false;

        const int n = dist_to_thief.size();
        queue<pair<int, int>> q{{{0, 0}}};
        vector<vector<bool>> seen(n, vector<bool>(n));
        seen[0][0] = true;

        while (!q.empty()) {
            const auto [i, j] = q.front();
            q.pop();
            if (dist_to_thief[i][j] < safeness)
                continue;
            if (i == n - 1 && j == n - 1)
                return true;
            for (const auto& [dx, dy] : dirs) {
                const int x = i + dx;
                const int y = j + dy;
                if (x < 0 || x == n || y < 0 || y == n)
                    continue;
                if (seen[x][y])
                    continue;
                q.emplace(x, y);
                seen[x][y] = true;
            }
        }

        return false;
    }

    vector<vector<int>> getdist_to_thief(const vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> dist_to_thief(n, vector<int>(n));
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(n, vector<bool>(n));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    seen[i][j] = true;
                }

        for (int dist = 0; !q.empty(); ++dist) {
            for (int sz = q.size(); sz > 0; --sz) {
                const auto [i, j] = q.front();
                q.pop();
                dist_to_thief[i][j] = dist;
                for (const auto& [dx, dy] : dirs) {
                    const int x = i + dx;
                    const int y = j + dy;
                    if (x < 0 || x == n || y < 0 || y == n)
                        continue;
                    if (seen[x][y])
                        continue;
                    q.emplace(x, y);
                    seen[x][y] = true;
                }
            }
        }

        return dist_to_thief;
    }
};