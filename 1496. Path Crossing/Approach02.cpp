#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPathCrossing(std::string path) {
        int x = 0;
        int y = 0;
        int n = path.size();
        unordered_set<string> s;
        string key = to_string(x)+"-"+to_string(y);
        s.insert(key);

        for (auto &ch: path) {
            if (ch == 'N') {
                y++;
            }else if (ch == 'S') {
                y--;
            }else if (ch == 'E') {
                x++;
            } else if (ch == 'W') {
                x--;
            } 
            key = to_string(x)+"-"+to_string(y);
            if (s.find(key) != s.end()) {
                return true;
            }
            s.insert(key);
        }

        return false;
    }
};