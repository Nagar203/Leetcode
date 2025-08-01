class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        // Initialize each row with 1s
        for (int rowIndex = 0; rowIndex < numRows; ++rowIndex)
            pascalTriangle.push_back(vector<int>(rowIndex + 1, 1));

        // Fill in the interior values
        for (int rowIndex = 2; rowIndex < numRows; ++rowIndex)
            for (int colIndex = 1; colIndex < pascalTriangle[rowIndex].size() - 1; ++colIndex)
                pascalTriangle[rowIndex][colIndex] = pascalTriangle[rowIndex - 1][colIndex - 1] + pascalTriangle[rowIndex - 1][colIndex];

        return pascalTriangle;
    }
};
