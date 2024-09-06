#include <unordered_set>
#include <vector>

class Solution {
public:
    ListNode* modifiedList(const std::vector<int>& nums, ListNode* head) {
        // Create a dummy node to handle edge cases.
        ListNode* result = new ListNode(0, head);
        
        // Convert the vector into an unordered set for quick lookup.
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        ListNode* currentNode = result;
        
        // Traverse the linked list.
        while (currentNode->next) {
            if (numSet.find(currentNode->next->val) != numSet.end()) {
                // If the next node's value is in the set, skip it.
                currentNode->next = currentNode->next->next;
            } else {
                // Otherwise, move to the next node.
                currentNode = currentNode->next;
            }
        }
        
        return result->next; // Return the new head of the modified list.
    }
};