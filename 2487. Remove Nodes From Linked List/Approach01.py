class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNodes(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        head.next = self.removeNodes(head.next)
        return head.next if head.next is not None and head.val < head.next.val else head
