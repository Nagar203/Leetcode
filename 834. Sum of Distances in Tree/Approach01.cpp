#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> result(n);
        vector<int> count(n, 1);
        vector<unordered_set<int>> tree(n);

        for (const vector<int>& edge : edges) {
            const int u = edge[0];
            const int v = edge[1];
            tree[u].insert(v);
            tree[v].insert(u);
        }

        post_order(tree, 0, -1, count, result);
        pre_order(tree, 0, -1, count, result);
        return result;
    }

private:
    void post_order(const vector<unordered_set<int>>& tree, int node,
                    int parent, vector<int>& count, vector<int>& result) {
        for (const int child : tree[node]) {
            if (child == parent)
                continue;
            post_order(tree, child, node, count, result);
            count[node] += count[child];
            result[node] += result[child] + count[child];
        }
    }

    void pre_order(const vector<unordered_set<int>>& tree, int node, int parent,
                   vector<int>& count, vector<int>& result) {
        for (const int child : tree[node]) {
            if (child == parent) {
                continue;
            }
            result[child] =
                result[node] - count[child] + (tree.size() - count[child]);
            pre_order(tree, child, node, count, result);
        }
    }
};