class Node:
    def __init__(self, count):
        self.count = count
        self.keys = set()

class AllOne:
    def __init__(self):
        self.nodeList = []  # List of nodes sorted by count
        self.keyToNode = {}  # Map from key to corresponding node

    # Increment the count of the given key
    def inc(self, key):
        if key not in self.keyToNode:
            self.addNewKey(key)
        else:
            self.incrementExistingKey(key)

    # Decrement the count of the given key
    def dec(self, key):
        if key in self.keyToNode:
            self.decrementExistingKey(key)

    # Return the key with the maximum count
    def getMaxKey(self):
        return next(iter(self.nodeList[-1].keys)) if self.nodeList else ""

    # Return the key with the minimum count
    def getMinKey(self):
        return next(iter(self.nodeList[0].keys)) if self.nodeList else ""

    # Add a new key with count 1
    def addNewKey(self, key):
        if not self.nodeList or self.nodeList[0].count > 1:
            newNode = Node(1)
            newNode.keys.add(key)
            self.nodeList.insert(0, newNode)
        else:
            self.nodeList[0].keys.add(key)
        self.keyToNode[key] = self.nodeList[0]

    # Increment the count of an existing key
    def incrementExistingKey(self, key):
        currentNode = self.keyToNode[key]
        newCount = currentNode.count + 1

        nextNode = None
        # Check if the next node exists and has the correct count
        if self.nodeList.index(currentNode) + 1 < len(self.nodeList) and \
                self.nodeList[self.nodeList.index(currentNode) + 1].count == newCount:
            nextNode = self.nodeList[self.nodeList.index(currentNode) + 1]
        else:
            nextNode = Node(newCount)
            self.nodeList.insert(self.nodeList.index(currentNode) + 1, nextNode)

        nextNode.keys.add(key)
        self.keyToNode[key] = nextNode
        self.removeKeyFromNode(currentNode, key)

    # Decrement the count of an existing key
    def decrementExistingKey(self, key):
        currentNode = self.keyToNode[key]
        newCount = currentNode.count - 1

        if newCount == 0:
            del self.keyToNode[key]
            self.removeKeyFromNode(currentNode, key)
            return

        prevNode = None
        # Check if the previous node exists and has the correct count
        if self.nodeList.index(currentNode) > 0 and \
                self.nodeList[self.nodeList.index(currentNode) - 1].count == newCount:
            prevNode = self.nodeList[self.nodeList.index(currentNode) - 1]
        else:
            prevNode = Node(newCount)
            self.nodeList.insert(self.nodeList.index(currentNode), prevNode)

        prevNode.keys.add(key)
        self.keyToNode[key] = prevNode
        self.removeKeyFromNode(currentNode, key)

    # Remove the key from the node, and erase the node if empty
    def removeKeyFromNode(self, node, key):
        node.keys.remove(key)
        if not node.keys:
            self.nodeList.remove(node)