from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        cnt = 0
        list2_last_node = ListNode()
        temp = list2
        while(temp != None):
            list2_last_node = temp
            temp = temp.next
        temp = list1
        prev = ListNode()

        while(temp != None):
            if(cnt == a):
                prev.next = list2
            if(cnt == b):
                list2_last_node.next = temp.next
            prev = temp
            temp = temp.next
            cnt += 1
        return list1