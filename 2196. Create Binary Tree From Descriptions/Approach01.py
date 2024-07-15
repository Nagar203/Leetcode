from typing import List
from collections import defaultdict

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> TreeNode:
        childToParentMap = {}
        valueToNodeMap = {}

        for description in descriptions:
            parentValue = description[0]
            childValue = description[1]
            isLeftChild = description[2]

            if parentValue not in valueToNodeMap:
                valueToNodeMap[parentValue] = TreeNode(parentValue)
            parentNode = valueToNodeMap[parentValue]

            if childValue not in valueToNodeMap:
                valueToNodeMap[childValue] = TreeNode(childValue)
            childNode = valueToNodeMap[childValue]

            childToParentMap[childNode] = parentNode

            if isLeftChild:
                parentNode.left = childNode
            else:
                parentNode.right = childNode

        # Pick a random node and traverse upward to find the root.
        root = next(iter(childToParentMap.values()))
        while root in childToParentMap:
            root = childToParentMap[root]

        return root
