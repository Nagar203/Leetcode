#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int unguardedCount = 0;
        vector<vector<char>> grid(rows, vector<char>(cols));
        vector<vector<char>> leftGuard(rows, vector<char>(cols));
        vector<vector<char>> rightGuard(rows, vector<char>(cols));
        vector<vector<char>> upGuard(rows, vector<char>(cols));
        vector<vector<char>> downGuard(rows, vector<char>(cols));

        // Mark guards and walls on the grid
        for (const vector<int>& guard : guards){
            grid[guard[0]][guard[1]] = 'G';
        }

        for (const vector<int>& wall : walls){
            grid[wall[0]][wall[1]] = 'W';
        }

        // Fill guard visibility from left and right
        for (int i = 0; i < rows; ++i) {
            char lastSeen = 0;
            for (int j = 0; j < cols; ++j){
                updateGuardInfo(grid[i][j], lastSeen, leftGuard[i][j]);
            }
            lastSeen = 0;
            for (int j = cols - 1; j >= 0; --j){
                updateGuardInfo(grid[i][j], lastSeen, rightGuard[i][j]);
            }
        }

        // Fill guard visibility from top and bottom
        for (int j = 0; j < cols; ++j) {
            char lastSeen = 0;
            for (int i = 0; i < rows; ++i){
                updateGuardInfo(grid[i][j], lastSeen, upGuard[i][j]);
            }
            lastSeen = 0;
            for (int i = rows - 1; i >= 0; --i){
                updateGuardInfo(grid[i][j], lastSeen, downGuard[i][j]);
            }
                
        }

        // Count unguarded cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0 && leftGuard[i][j] != 'G' &&
                    rightGuard[i][j] != 'G' && upGuard[i][j] != 'G' &&
                    downGuard[i][j] != 'G') {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }

private:
    void updateGuardInfo(char currentCell, char& lastSeen, char& guardInfo) {
        if (currentCell == 'G' || currentCell == 'W'){
            lastSeen = currentCell;
        }
        else{
            guardInfo = lastSeen;
        }
    }
};