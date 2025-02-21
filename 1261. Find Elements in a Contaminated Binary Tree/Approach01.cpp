class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        return result.contains(target);
    }

private:
    unordered_set<int> result;

    void dfs(TreeNode* root, int value){
        if(root==nullptr){
            return;
        }
        root->val = value;
        result.insert(value);
        dfs(root->left, value*2+1);
        dfs(root->right, value*2+2);
    }
};