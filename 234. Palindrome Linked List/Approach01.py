from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        result = []

        if(not head):
            return 
        
        while(head is not None):
            result.append(head.val)
            head = head.next
        return (result==result[::-1])
        