from typing import *

class TrieNode:
    def __init__(self):
        # Array of TrieNode pointers for 26 lowercase letters (a to z)
        self.children = [None] * 26
        # Keeps track of the prefix count
        self.prefixCount = 0


class Solution:
    def sumPrefixScores(self, words):
        prefixScores = []
        # Initialize the root of the Trie
        root = TrieNode()

        # Insert all words into the Trie
        for word in words:
            self.insertWord(word, root)

        # Calculate prefix scores for all words
        for word in words:
            prefixScores.append(self.calculatePrefixScore(word, root))

        return prefixScores

    # Inserts a word into the Trie
    def insertWord(self, word, root):
        currentNode = root
        for character in word:
            index = ord(character) - ord('a')
            if not currentNode.children[index]:
                currentNode.children[index] = TrieNode()
            currentNode = currentNode.children[index]
            currentNode.prefixCount += 1

    # Calculates the score for the given word based on the Trie
    def calculatePrefixScore(self, word, root):
        currentNode = root
        totalScore = 0
        for character in word:
            index = ord(character) - ord('a')
            currentNode = currentNode.children[index]
            totalScore += currentNode.prefixCount
        return totalScore