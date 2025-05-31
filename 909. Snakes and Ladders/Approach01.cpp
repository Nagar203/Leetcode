class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattenedBoard(n * n);
        int row = n - 1, col = 0, index = 0, direction = 1;

        while (index < n * n) {
            flattenedBoard[index++] = board[row][col];
            if (direction == 1 && col == n - 1) {
                direction = -1;
                row--;
            } else if (direction == -1 && col == 0) {
                direction = 1;
                row--;
            } else {
                col += direction;
            }
        }

        vector<bool> visited(n * n, false);
        queue<int> bfsQueue;
        int startSquare = flattenedBoard[0] > -1 ? flattenedBoard[0] - 1 : 0;

        bfsQueue.push(startSquare);
        visited[startSquare] = true;

        int moves = 0;

        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();
            while (levelSize-- > 0) {
                int current = bfsQueue.front();
                bfsQueue.pop();

                if (current == n * n - 1){
                    return moves;
                }
                    
                for (int next = current + 1;
                    next <= min(current + 6, n * n - 1); ++next) {
                    int destination = flattenedBoard[next] > -1 ? flattenedBoard[next] - 1 : next;
                    if (!visited[destination]) {
                        visited[destination] = true;
                        bfsQueue.push(destination);
                    }
                }
            }
            ++moves;
        }

        return -1;
    }
};