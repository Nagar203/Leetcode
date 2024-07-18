#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int pairCount = 0;
        dfs(root, distance, pairCount);
        return pairCount;
    }

private:
    vector<int> dfs(TreeNode* root, int maxDistance, int& pairCount) {
        vector<int> distances(maxDistance + 1);  // {distance: the number of leaf nodes}
        if (root == nullptr)
            return distances;
        if (root->left == nullptr && root->right == nullptr) {
            distances[0] = 1;
            return distances;
        }

        const vector<int> leftDistances = dfs(root->left, maxDistance, pairCount);
        const vector<int> rightDistances = dfs(root->right, maxDistance, pairCount);

        for (int leftDist = 0; leftDist < maxDistance; ++leftDist)
            for (int rightDist = 0; rightDist < maxDistance; ++rightDist)
                if (leftDist + rightDist + 2 <= maxDistance)
                    pairCount += leftDistances[leftDist] * rightDistances[rightDist];

        for (int dist = 0; dist < maxDistance; ++dist)
            distances[dist + 1] = leftDistances[dist] + rightDistances[dist];

        return distances;
    }
};
