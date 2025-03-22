#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int size)
        : parent(size), rank(size), componentSize(size, 1), edgeCount(size) {
        iota(parent.begin(), parent.end(), 0);
    }

    void unionByRank(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        ++edgeCount[root1];

        if (root1 == root2)
            return;

        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
            edgeCount[root2] += edgeCount[root1];
            componentSize[root2] += componentSize[root1];
        } else if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
            edgeCount[root1] += edgeCount[root2];
            componentSize[root1] += componentSize[root2];
        } else {
            parent[root1] = root2;
            edgeCount[root2] += edgeCount[root1];
            componentSize[root2] += componentSize[root1];
            ++rank[root2];
        }
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }

    bool isCompleteComponent(int node) {
        return componentSize[node] * (componentSize[node] - 1) / 2 ==
               edgeCount[node];
    }

private:
    vector<int> parent;
    vector<int> rank;
    vector<int> componentSize;
    vector<int> edgeCount;
};

class Solution {
public:
    int countCompleteComponents(int totalNodes, vector<vector<int>>& edges) {
        int completeComponents = 0;
        UnionFind uf(totalNodes);
        unordered_set<int> uniqueParents;

        for (const vector<int>& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            uf.unionByRank(node1, node2);
        }

        for (int node = 0; node < totalNodes; ++node) {
            int root = uf.find(node);
            if (uniqueParents.insert(root).second &&
                uf.isCompleteComponent(root))
                ++completeComponents;
        }

        return completeComponents;
    }
};
