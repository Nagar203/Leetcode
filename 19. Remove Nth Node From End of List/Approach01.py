from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        cnt = 0
        temp = head

        while(temp != None):
            cnt += 1
            temp = temp.next
        if(cnt == n):
            prev = head.next
            del head
            head = prev
            return head
        temp = head
        prev = None
        target = cnt - n + 1
        cnt = 0
        while(temp != None):
            cnt += 1
            if(cnt == target):
                prev.next = temp.next
                del temp    
                break
            prev = temp
            temp = temp.next
        return head