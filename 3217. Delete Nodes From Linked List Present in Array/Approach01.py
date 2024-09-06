from typing import *

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode(0, head)
        nums = set(nums)
        currentNode = result

        while(currentNode.next):
            if(currentNode.next.val in nums):
                currentNode.next = currentNode.next.next
            else:
                currentNode = currentNode.next
        return result.next