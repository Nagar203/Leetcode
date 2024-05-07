from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        current = head
        while current is not None:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        total = 0
        temp = head
        while temp is not None:
            total = total * 10 + temp.val
            temp = temp.next
        total *= 2

        result = ListNode()
        node = result
        if total == 0:
            return ListNode(0) 

        while total > 0:
            digit = total % 10
            total //= 10
            node.next = ListNode(digit)
            node = node.next

        return self.reverseList(result.next)

