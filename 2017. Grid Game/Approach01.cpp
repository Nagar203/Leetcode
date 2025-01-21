class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int numCols = grid[0].size(); // Number of columns in the grid
        long minPoints = LONG_MAX; // Minimum points robot 2 can collect
        long upperRowSum = accumulate(grid[0].begin(), grid[0].end(), 0L); // Total points in the upper row
        long lowerRowSum = 0;              // Points collected in the lower row

        // Iterate through each column as the split point
        for (int col = 0; col < numCols; ++col) {
            upperRowSum -= grid[0][col]; // Deduct the points collected from the upper row
            // Calculate the maximum points robot 2 can collect at this split point
            minPoints = min(minPoints, max(upperRowSum, lowerRowSum));
            lowerRowSum +=
                grid[1][col]; // Add the points collected from the lower row
        }

        return minPoints;
    }
};