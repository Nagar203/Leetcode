#include <unordered_set>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the total number of nodes in the linked list
        int totalNodes = 0;
        ListNode* current = head;
        while (current) {
            totalNodes++;
            current = current->next;
        }

        // Step 2: Determine the size of each part and the extra nodes
        int nodesPerPart = totalNodes / k;
        int extraNodes = totalNodes % k;  // Nodes to be distributed in the first 'extraNodes' parts

        // Step 3: Initialize result list
        vector<ListNode*> result(k, nullptr);
        current = head;

        // Step 4: Split the linked list into parts
        for (int i = 0; i < k; ++i) {
            ListNode* partHead = current;
            int partSize = nodesPerPart + (i < extraNodes ? 1 : 0);  // Determine the size of the current part

            // Traverse 'partSize' nodes for the current part
            for (int j = 0; j < partSize - 1 && current; ++j) {
                current = current->next;
            }

            // If there are nodes in the current part, detach it from the rest
            if (current) {
                ListNode* nextPartHead = current->next;
                current->next = nullptr;  // End the current part
                current = nextPartHead;  // Move to the next part's head
            }

            // Append the head of the current part to the result
            result[i] = partHead;
        }

        return result;
    }
};