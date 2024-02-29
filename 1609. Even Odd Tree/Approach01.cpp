#include <queue>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;

        while (!q.empty()) {
            int prev = evenLevel ? INT_MIN : INT_MAX;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if ((evenLevel && (curr->val % 2 == 0 || curr->val <= prev)) ||
                    (!evenLevel && (curr->val % 2 != 0 || curr->val >= prev))) {
                    return false;
                }

                prev = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            evenLevel = !evenLevel;
        }

        return true;
    }
};
