#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorderTraversal(root, nums);
        return buildBalancedBST(nums, 0, nums.size() - 1);
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }

    TreeNode* buildBalancedBST(const vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBalancedBST(nums, left, mid - 1);
        root->right = buildBalancedBST(nums, mid + 1, right);
        return root;
    }
};
