from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        d = {0: dummy}
        curr = head
        prefix = 0
        while curr:
            prefix += curr.val
            d[prefix] = curr
            curr = curr.next

        curr = dummy
        prefix = 0
        while curr:
            prefix += curr.val
            curr.next = d[prefix].next
            curr = curr.next
        return dummy.next