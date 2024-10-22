#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<long> levelSumList;
        calculateLevelSums(root, 0, levelSumList);
        if (levelSumList.size() < k)
            return -1;

        std::nth_element(levelSumList.begin(), levelSumList.begin() + k - 1, levelSumList.end(), std::greater<>());
        return levelSumList[k - 1];
    }

private:
    void calculateLevelSums(TreeNode* node, int currentLevel, std::vector<long>& levelSumList) {
        if (node == nullptr)
            return;
        if (levelSumList.size() == currentLevel)
            levelSumList.push_back(0);
        levelSumList[currentLevel] += node->val;
        calculateLevelSums(node->left, currentLevel + 1, levelSumList);
        calculateLevelSums(node->right, currentLevel + 1, levelSumList);
    }
};