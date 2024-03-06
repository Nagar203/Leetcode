from typing import *

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if(head == None or head.next == None or head.next.next == None):
            return False
        slow = head
        fast = head.next
        while(slow != fast):
            if(slow == None or fast == None):
                return False
            slow = slow.next
            if(fast.next == None):
                return False
            fast = fast.next.next
        return True