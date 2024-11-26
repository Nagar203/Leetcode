#include <vector>
using namespace std;

class Solution {
public:
    int findChampion(int numNodes, vector<vector<int>>& edges) {
        int potentialChampion = -1;
        int zeroInDegreeCount = 0;
        vector<int> inDegrees(numNodes);

        // Calculate in-degrees for each node
        for (const vector<int>& edge : edges) {
            const int targetNode = edge[1];
            ++inDegrees[targetNode];
        }

        // Identify nodes with zero in-degree
        for (int node = 0; node < numNodes; ++node) {
            if (inDegrees[node] == 0) {
                ++zeroInDegreeCount;
                potentialChampion = node;
            }
        }

        // If more than one node has zero in-degree, no champion exists
        return zeroInDegreeCount > 1 ? -1 : potentialChampion;
    }
};