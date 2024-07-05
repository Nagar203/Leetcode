#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_distance = numeric_limits<int>::max();
        int first_critical_index = -1;
        int prev_critical_index = -1;
        int index = 1;
        ListNode* prev_node = head;        // Pointer to the current node.
        ListNode* curr_node = head->next;  // Pointer to the next node.

        while (curr_node->next) {
            // Check for critical points (local maxima or minima).
            if ((curr_node->val > prev_node->val && curr_node->val > curr_node->next->val) ||
                (curr_node->val < prev_node->val && curr_node->val < curr_node->next->val)) {
                
                // First critical index (only set once).
                if (first_critical_index == -1) {
                    first_critical_index = index;
                }
                
                // Calculate minimum distance between consecutive critical points.
                if (prev_critical_index != -1) {
                    min_distance = min(min_distance, index - prev_critical_index);
                }
                
                prev_critical_index = index;
            }
            
            prev_node = curr_node;
            curr_node = curr_node->next;
            ++index;
        }

        if (min_distance == numeric_limits<int>::max()) {
            return {-1, -1};  // No critical points found.
        }
        
        // Calculate distance between the first and last critical points.
        int max_distance = prev_critical_index - first_critical_index;
        
        return {min_distance, max_distance};
    }
};

// Helper function to create a linked list
ListNode* create_list(vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}