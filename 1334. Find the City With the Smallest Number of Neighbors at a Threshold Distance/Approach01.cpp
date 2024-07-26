#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int resultCity = -1;
        int minReachableCities = n;
        const vector<vector<int>> distanceMatrix = floydWarshall(n, edges, distanceThreshold);

        // Iterate through each city to find the number of reachable cities within the distance threshold
        for (int currentCity = 0; currentCity < n; ++currentCity) {
            int reachableCitiesCount = 0;
            for (int targetCity = 0; targetCity < n; ++targetCity) {
                if (distanceMatrix[currentCity][targetCity] <= distanceThreshold) {
                    ++reachableCitiesCount;
                }
            }
            // Update the result city if the current city has fewer or equal reachable cities
            if (reachableCitiesCount <= minReachableCities) {
                resultCity = currentCity;
                minReachableCities = reachableCitiesCount;
            }
        }

        return resultCity;
    }

private:
    vector<vector<int>> floydWarshall(int n, const vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distanceMatrix(n, vector<int>(n, distanceThreshold + 1));

        // Initialize the distance of each city to itself as 0
        for (int i = 0; i < n; ++i) {
            distanceMatrix[i][i] = 0;
        }

        // Set the initial distances based on the given edges
        for (const vector<int>& edge : edges) {
            const int fromCity = edge[0];
            const int toCity = edge[1];
            const int weight = edge[2];
            distanceMatrix[fromCity][toCity] = weight;
            distanceMatrix[toCity][fromCity] = weight;
        }

        // Apply Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
        for (int intermediate = 0; intermediate < n; ++intermediate) {
            for (int start = 0; start < n; ++start) {
                for (int end = 0; end < n; ++end) {
                    distanceMatrix[start][end] = min(distanceMatrix[start][end], distanceMatrix[start][intermediate] + distanceMatrix[intermediate][end]);
                }
            }
        }

        return distanceMatrix;
    }
};
