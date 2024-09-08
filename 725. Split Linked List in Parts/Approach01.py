from typing import *

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        # Step 1: Count the total number of nodes in the linked list
        totalNodes = 0
        current = head
        while current:
            totalNodes += 1
            current = current.next

        # Step 2: Determine the size of each part and the extra nodes
        nodesPerPart = totalNodes // k
        extraNodes = totalNodes % k  # Nodes to be distributed in the first 'extraNodes' parts

        # Step 3: Initialize result list
        result = []
        current = head

        # Step 4: Split the linked list into parts
        for i in range(k):
            partHead = current
            partSize = nodesPerPart + (1 if i < extraNodes else 0)  # Determine the size of the current part

            # Traverse 'partSize' nodes for the current part
            for j in range(partSize - 1):
                if current:
                    current = current.next

            # If there are nodes in the current part, detach it from the rest
            if current:
                nextPartHead = current.next
                current.next = None  # End the current part
                current = nextPartHead  # Move to the next part's head

            # Append the head of the current part to the result
            result.append(partHead)

        # Step 5: If there are fewer nodes than k, append None for the remaining parts
        while len(result) < k:
            result.append(None)

        return result