#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> result(row, vector<int>(col, 0));

        int direction[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int sum = 0;
                int count = 0;

                for (int d = 0; d < 9; d++) {
                    int ni = i + direction[d][0];
                    int nj = j + direction[d][1];

                    if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
                        sum += img[ni][nj];
                        count++;
                    }
                }

                result[i][j] = sum / count;
            }
        }

        return result;
    }
};