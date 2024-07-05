from typing import *

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        import sys
        min_distance = sys.maxsize
        first_critical_index = -1
        prev_critical_index = -1
        index = 1
        prev_node = head  # Pointer to the current node.
        curr_node = head.next  # Pointer to the next node.

        while curr_node and curr_node.next:
            # Check for critical points (local maxima or minima).
            if (curr_node.val > prev_node.val and curr_node.val > curr_node.next.val) or \
               (curr_node.val < prev_node.val and curr_node.val < curr_node.next.val):
                
                # First critical index (only set once).
                if first_critical_index == -1:
                    first_critical_index = index
                
                # Calculate minimum distance between consecutive critical points.
                if prev_critical_index != -1:
                    min_distance = min(min_distance, index - prev_critical_index)
                
                prev_critical_index = index
            
            prev_node = curr_node
            curr_node = curr_node.next
            index += 1

        if min_distance == sys.maxsize:
            return [-1, -1]  # No critical points found.
        
        # Calculate distance between the first and last critical points.
        max_distance = prev_critical_index - first_critical_index
        
        return [min_distance, max_distance]

# Helper function to create a linked list
def create_list(values: List[int]) -> ListNode:
    dummy = ListNode(0)
    current = dummy
    for val in values:
        current.next = ListNode(val)
        current = current.next
    return dummy.next