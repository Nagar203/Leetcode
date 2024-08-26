#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> postorder(Node* root) {
        if (root == nullptr){
            return {};
        }

        vector<int> result;
        stack<Node*> stack{{root}};

        while (!stack.empty()) {
            root = stack.top(), stack.pop();
            result.push_back(root->val);
            for (Node* child : root->children){
                stack.push(child);
            }
        }

        ranges::reverse(result);
        return result;
    }
};