from collections import deque

class Solution:
    def replaceValueInTree(self, root: TreeNode) -> TreeNode:
        root.val = 0
        nodeQueue = deque([root])

        while nodeQueue:
            levelSize = len(nodeQueue)
            levelSum = 0
            nodesAtCurrentLevel = []

            # Process each node at the current level
            for _ in range(levelSize):
                currentNode = nodeQueue.popleft()
                nodesAtCurrentLevel.append(currentNode)

                if currentNode.left:
                    nodeQueue.append(currentNode.left)
                    levelSum += currentNode.left.val
                if currentNode.right:
                    nodeQueue.append(currentNode.right)
                    levelSum += currentNode.right.val

            # Replace node values based on cousin sum
            for currentNode in nodesAtCurrentLevel:
                cousinSum = levelSum
                if currentNode.left:
                    cousinSum -= currentNode.left.val
                if currentNode.right:
                    cousinSum -= currentNode.right.val
                if currentNode.left:
                    currentNode.left.val = cousinSum
                if currentNode.right:
                    currentNode.right.val = cousinSum

        return root
