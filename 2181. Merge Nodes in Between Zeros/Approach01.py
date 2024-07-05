from typing import *

class Solution:
    def mergeNodes(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        if not head.next or head.next.val == 0:
            node = ListNode(head.val)
            node.next = self.mergeNodes(head.next.next if head.next else None)
            return node
        
        next_node = self.mergeNodes(head.next)
        next_node.val += head.val
        return next_node