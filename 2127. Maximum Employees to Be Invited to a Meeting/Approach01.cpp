#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

enum class State { kInit, kVisiting, kVisited };

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int numPeople = favorite.size();
        int totalComponentLength = 0;  // Length of all 2-cycle components.
        vector<vector<int>> adjacencyList(numPeople);
        vector<int> inDegrees(numPeople, 0);
        vector<int> longestChainLength(numPeople, 1);

        // Build the graph using the favorite list.
        for (int person = 0; person < numPeople; ++person) {
            int likedPerson = favorite[person];
            adjacencyList[person].push_back(likedPerson);
            ++inDegrees[likedPerson];
        }

        // Perform topological sorting to calculate maximum chain lengths.
        queue<int> processingQueue;
        for (int person = 0; person < numPeople; ++person) {
            if (inDegrees[person] == 0) {
                processingQueue.push(person);
            }
        }

        while (!processingQueue.empty()) {
            int currentPerson = processingQueue.front();
            processingQueue.pop();
            for (int neighbor : adjacencyList[currentPerson]) {
                --inDegrees[neighbor];
                if (inDegrees[neighbor] == 0) {
                    processingQueue.push(neighbor);
                }
                longestChainLength[neighbor] = max(longestChainLength[neighbor], 1 + longestChainLength[currentPerson]);
            }
        }

        // Calculate the total length of all 2-cycle components.
        for (int person = 0; person < numPeople; ++person) {
            if (favorite[favorite[person]] == person) {
                // Found a 2-cycle: person <-> favorite[person].
                totalComponentLength += longestChainLength[person] + longestChainLength[favorite[person]];
            }
        }

        int maxCycleLength = 0;  // Longest cycle in the graph.
        vector<int> parent(numPeople, -1);
        unordered_set<int> visitedNodes;
        vector<State> nodeStates(numPeople, State::kInit);

        // Helper function to find the length of a cycle.
        auto findCycle = [&](int node, auto&& findCycleRef) -> void {
            visitedNodes.insert(node);
            nodeStates[node] = State::kVisiting;
            for (int neighbor : adjacencyList[node]) {
                if (visitedNodes.find(neighbor) == visitedNodes.end()) {
                    parent[neighbor] = node;
                    findCycleRef(neighbor, findCycleRef);
                } else if (nodeStates[neighbor] == State::kVisiting) {
                    // Found a cycle, calculate its length.
                    int currentNode = node;
                    int cycleLength = 1;
                    while (currentNode != neighbor) {
                        currentNode = parent[currentNode];
                        ++cycleLength;
                    }
                    maxCycleLength = max(maxCycleLength, cycleLength);
                }
            }
            nodeStates[node] = State::kVisited;
        };

        // Start DFS from every unvisited node to detect cycles.
        for (int person = 0; person < numPeople; ++person) {
            if (visitedNodes.find(person) == visitedNodes.end()) {
                findCycle(person, findCycle);
            }
        }

        return max(totalComponentLength / 2, maxCycleLength);
    }
};