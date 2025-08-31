class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 
        backtrack(board, 0); 
    }

private:
    bool backtrack(vector<vector<char>>& board, int cellIndex) {
        if (cellIndex == 81) // All cells filled
            return true;

        int rowIndex = cellIndex / 9;
        int colIndex = cellIndex % 9;

        if (board[rowIndex][colIndex] != '.')
            return backtrack(board, cellIndex + 1);

        for (char digit = '1'; digit <= '9'; ++digit) {
            if (isValidPlacement(board, rowIndex, colIndex, digit)) {
                board[rowIndex][colIndex] = digit;
                if (backtrack(board, cellIndex + 1))
                    return true;
                board[rowIndex][colIndex] = '.'; // Undo choice
            }
        }

        return false;
    }

    bool isValidPlacement(vector<vector<char>>& board, int rowIndex, int colIndex, char digit) {
        for (int index = 0; index < 9; ++index) {
            if (board[index][colIndex] == digit || 
                board[rowIndex][index] == digit ||
                board[3 * (rowIndex / 3) + index / 3][3 * (colIndex / 3) + index % 3] == digit)
                return false;
        }
        return true;
    }
};
