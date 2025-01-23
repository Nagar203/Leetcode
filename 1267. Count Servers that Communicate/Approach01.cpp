class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int numRows = grid.size();
        const int numCols = grid[0].size();
        int serverCount = 0;
        vector<int> rowCounts(numRows); // Number of servers in each row
        vector<int> colCounts(numCols); // Number of servers in each column

        // Count the servers in each row and column
        for (int row = 0; row < numRows; ++row)
            for (int col = 0; col < numCols; ++col)
                if (grid[row][col] == 1) {
                    ++rowCounts[row];
                    ++colCounts[col];
                }

        // Count servers that can communicate
        for (int row = 0; row < numRows; ++row)
            for (int col = 0; col < numCols; ++col)
                if (grid[row][col] == 1 && (rowCounts[row] > 1 || colCounts[col] > 1))
                    ++serverCount;

        return serverCount;
    }
};
