#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        long totalCost = 0;
        // distanceMatrix[u][v] represents the minimum cost to change character ('a' + u) to character ('a' + v)
        vector<vector<long>> distanceMatrix(26, vector<long>(26, LONG_MAX));

        // Initialize the distance matrix with the given costs
        for (int i = 0; i < cost.size(); ++i) {
            const int sourceChar = original[i] - 'a';
            const int targetChar = changed[i] - 'a';
            distanceMatrix[sourceChar][targetChar] = min(distanceMatrix[sourceChar][targetChar], static_cast<long>(cost[i]));
        }

        // Apply the Floyd-Warshall algorithm to compute the shortest paths between all pairs of characters
        for (int intermediate = 0; intermediate < 26; ++intermediate) {
            for (int start = 0; start < 26; ++start) {
                if (distanceMatrix[start][intermediate] < LONG_MAX) {
                    for (int end = 0; end < 26; ++end) {
                        if (distanceMatrix[intermediate][end] < LONG_MAX) {
                            distanceMatrix[start][end] = min(distanceMatrix[start][end], distanceMatrix[start][intermediate] + distanceMatrix[intermediate][end]);
                        }
                    }
                }
            }
        }

        // Calculate the total minimum cost to change the source string to the target string
        for (int i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            const int sourceChar = source[i] - 'a';
            const int targetChar = target[i] - 'a';
            if (distanceMatrix[sourceChar][targetChar] == LONG_MAX) {
                return -1;
            }
            totalCost += distanceMatrix[sourceChar][targetChar];
        }

        return totalCost;
    }
};
