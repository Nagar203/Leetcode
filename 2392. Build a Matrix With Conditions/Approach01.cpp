class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Perform topological sorting for rows
        const vector<int> rowOrder = topologicalSort(rowConditions, k);
        if (rowOrder.empty())
            return {};

        // Perform topological sorting for columns
        const vector<int> colOrder = topologicalSort(colConditions, k);
        if (colOrder.empty())
            return {};

        // Initialize the result matrix
        vector<vector<int>> matrix(k, vector<int>(k));
        vector<int> nodeToRowIndex(k + 1);

        // Map nodes to their row indices based on rowOrder
        for (int row = 0; row < k; ++row)
            nodeToRowIndex[rowOrder[row]] = row;

        // Fill in the matrix based on the column order
        for (int col = 0; col < k; ++col) {
            const int node = colOrder[col];
            const int row = nodeToRowIndex[node];
            matrix[row][col] = node;
        }

        return matrix;
    }

private:
    // Perform topological sort on a directed graph defined by conditions
    vector<int> topologicalSort(const vector<vector<int>>& conditions, int n) {
        vector<int> sortedOrder;            // To store the topological order
        vector<vector<int>> adjList(n + 1); // Adjacency list for the graph
        vector<int> inDegrees(n + 1, 0);    // In-degree count for each node
        queue<int> zeroInDegreeNodes; // Queue for nodes with zero in-degree

        // Build the graph from conditions
        for (const vector<int>& condition : conditions) {
            const int from = condition[0];
            const int to = condition[1];
            adjList[from].push_back(to);
            ++inDegrees[to];
        }

        // Initialize the queue with nodes having zero in-degree
        for (int i = 1; i <= n; ++i)
            if (inDegrees[i] == 0)
                zeroInDegreeNodes.push(i);

        // Perform Kahn's algorithm for topological sorting
        while (!zeroInDegreeNodes.empty()) {
            const int node = zeroInDegreeNodes.front();
            zeroInDegreeNodes.pop();
            sortedOrder.push_back(node);
            for (const int neighbor : adjList[node])
                if (--inDegrees[neighbor] == 0)
                    zeroInDegreeNodes.push(neighbor);
        }

        // Check if a valid topological sort was found
        return sortedOrder.size() == n ? sortedOrder : vector<int>();
    }
};
