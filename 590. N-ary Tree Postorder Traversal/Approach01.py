from typing import *

class Solution:
    def postorder(self, root: 'Node') -> list[int]:
        if not root:
            return []

        result = []
        stack = [root]

        while stack:
            node = stack.pop()
            result.append(node.val)
            for child in node.children:
                stack.append(child)

        result.reverse()
        return result