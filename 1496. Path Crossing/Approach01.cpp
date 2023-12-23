#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPathCrossing(std::string path) {
        int x = 0;
        int y = 0;
        int n = path.size();
        set<pair<int, int>> s;
        s.insert({x, y});

        for (int i = 0; i < n; i++) {
            if (path[i] == 'N') {
                y++;
            } else if (path[i] == 'E') {
                x++;
            } else if (path[i] == 'W') {
                x--;
            } else if (path[i] == 'S') {
                y--;
            }

            auto value = s.find({x, y});
            if (value != s.end()) {
                return true;
            }
            s.insert({x, y});
        }

        return false;
    }
};