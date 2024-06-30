#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) : count(n), id(n), rank(n) {
        iota(id.begin(), id.end(), 0);
    }

    bool union_by_rank(int u, int v) {
        const int root_u = find(u);
        const int root_v = find(v);
        if (root_u == root_v)
            return false;
        if (rank[root_u] < rank[root_v]) {
            id[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            id[root_v] = root_u;
        } else {
            id[root_u] = root_v;
            ++rank[root_v];
        }
        --count;
        return true;
    }

    int get_count() const { return count; }

private:
    int count;
    vector<int> id;
    vector<int> rank;

    int find(int u) { return id[u] == u ? u : id[u] = find(id[u]); }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n);
        UnionFind bob(n);
        int required_edges = 0;

        // Greedily put type 3 edges in the front.
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] > b[0];
             });

        for (const vector<int>& edge : edges) {
            const int type = edge[0];
            const int u = edge[1] - 1;
            const int v = edge[2] - 1;
            switch (type) {
            case 3: // Can be traversed by Alice and Bob.
                if (alice.union_by_rank(u, v) | bob.union_by_rank(u, v))
                    ++required_edges;
                break;
            case 2: // Can be traversed by Bob.
                if (bob.union_by_rank(u, v))
                    ++required_edges;
                break; // Added break statement here
            case 1:    // Can be traversed by Alice.
                if (alice.union_by_rank(u, v))
                    ++required_edges;
                break; // Added break statement here
            }
        }

        return alice.get_count() == 1 && bob.get_count() == 1 ? edges.size() - required_edges : -1;
    }
};