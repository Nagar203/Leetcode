class TrieNode:
    def __init__(self):
        # Initializes children for digits 0-9
        self.children = [None] * 10

class Trie:
    def __init__(self):
        # Root of the Trie
        self.root = TrieNode()

    # Insert a number string into the Trie
    def insert(self, numberString):
        currentNode = self.root
        for digit in numberString:
            index = ord(digit) - ord('0')  # Convert character to corresponding index
            if currentNode.children[index] is None:
                currentNode.children[index] = TrieNode()
            currentNode = currentNode.children[index]

    # Search for the longest common prefix of a number string
    def search(self, numberString):
        commonPrefixLength = 0
        currentNode = self.root
        for digit in numberString:
            index = ord(digit) - ord('0')
            if currentNode.children[index] is None:
                break
            currentNode = currentNode.children[index]
            commonPrefixLength += 1
        return commonPrefixLength

class Solution:
    # Function to find the longest common prefix between two arrays of integers
    def longestCommonPrefix(self, array1: List[int], array2: List[int]) -> int:
        maxPrefixLength = 0
        trie = Trie()

        # Insert all numbers from array1 into the Trie
        for number in array1:
            trie.insert(str(number))

        # Search for the longest common prefix with numbers in array2
        for number in array2:
            maxPrefixLength = max(maxPrefixLength, trie.search(str(number)))

        return maxPrefixLength