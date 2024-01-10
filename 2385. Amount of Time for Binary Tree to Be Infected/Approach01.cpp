#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
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
    void create_graph(unordered_map<int, vector<int>> &data, int parent, TreeNode* curr){
        if(curr==NULL){
            return;
        }
        if(parent != -1){
            data[curr->val].push_back(parent);
        }
        if(curr->left != NULL){
            data[curr->val].push_back(curr->left->val);
        }
        if(curr->right != NULL){
            data[curr->val].push_back(curr->right->val);
        }
        create_graph(data, curr->val, curr->left);
        create_graph(data, curr->val, curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> data;

        create_graph(data, -1, root);

        queue<int> q;
        unordered_set<int> visited_node;
        q.push(start);
        visited_node.insert(start);
        int time = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int curr_info = q.front();
                q.pop();
                for(auto &nbr: data[curr_info]){
                    if(visited_node.find(nbr) == visited_node.end()){
                        q.push(nbr);
                        visited_node.insert(nbr);
                    }
                }
            }
            time++;
        }
        time -= 1;
        return time;
    }
};