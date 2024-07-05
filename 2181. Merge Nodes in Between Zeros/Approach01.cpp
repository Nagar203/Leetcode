#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        if (!head->next || head->next->val == 0) {
            ListNode* node = new ListNode(head->val);
            node->next = mergeNodes(head->next ? head->next->next : nullptr);
            return node;
        }

        ListNode* next_node = mergeNodes(head->next);
        next_node->val += head->val;
        return next_node;
    }
};