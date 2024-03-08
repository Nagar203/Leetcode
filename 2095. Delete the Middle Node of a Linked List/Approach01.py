from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head == None or head.next == None):
            return None
        slow, fast, prev = head, head, None
        while(fast != None and fast.next != None):
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = slow.next
        del slow
        return head