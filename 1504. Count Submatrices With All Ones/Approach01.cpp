class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int rowCount = mat.size();
        const int colCount = mat[0].size();
        int totalSubmatrices = 0;

        for (int startRow = 0; startRow < rowCount; ++startRow) {
            vector<int> validCols(colCount, 1);
            for (int currentRow = startRow; currentRow < rowCount; ++currentRow) {
                for (int col = 0; col < colCount; ++col)
                    validCols[col] &= mat[currentRow][col];
                totalSubmatrices += count(validCols);
            }
        }

        return totalSubmatrices;
    }

private:
    int count(vector<int>& validCols) {
        int submatrixCount = 0;
        int consecutiveOnes = 0;
        for (const int val : validCols) {
            consecutiveOnes = (val == 0) ? 0 : consecutiveOnes + 1;
            submatrixCount += consecutiveOnes;
        }
        return submatrixCount;
    }
};
