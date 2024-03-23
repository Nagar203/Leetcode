from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None or head.next is None:
            return
        
        nodes = []
        temp = head
        while temp:
            nodes.append(temp)
            temp = temp.next

        length = len(nodes)
        even_nodes = nodes[:length // 2]
        odd_nodes = nodes[length // 2:]
        
        if length % 2 != 0:
            even_nodes = nodes[:length // 2 + 1]
            odd_nodes = nodes[length // 2 + 1:]

        length_odd_node = length // 2
        head = even_nodes[0]
        prev = None
        
        for i in range(length_odd_node):
            first_node = even_nodes[i]
            second_node = odd_nodes[-i - 1]
            if prev:
                prev.next = first_node
            first_node.next = second_node
            prev = second_node
        
        if len(odd_nodes) < len(even_nodes):
            prev.next = even_nodes[-1]
            even_nodes[-1].next = None
        else:
            prev.next = None
