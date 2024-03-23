#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int length = nodes.size();
        vector<ListNode*> even_nodes(nodes.begin(), nodes.begin() + length / 2);
        vector<ListNode*> odd_nodes(nodes.begin() + length / 2, nodes.end());
        
        if (length % 2 != 0) {
            even_nodes.assign(nodes.begin(), nodes.begin() + length / 2 + 1);
            odd_nodes.assign(nodes.begin() + length / 2 + 1, nodes.end());
        }

        int length_odd_node = length / 2;
        head = even_nodes[0];
        ListNode* prev = nullptr;
        
        for (int i = 0; i < length_odd_node; ++i) {
            ListNode* first_node = even_nodes[i];
            ListNode* second_node = odd_nodes[length_odd_node - i - 1];
            if (prev)
                prev->next = first_node;
            first_node->next = second_node;
            prev = second_node;
        }
        
        if (odd_nodes.size() < even_nodes.size()) {
            prev->next = even_nodes.back();
            even_nodes.back()->next = nullptr;
        } else {
            prev->next = nullptr;
        }
    }
};