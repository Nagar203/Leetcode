from typing import *
from typing import List


class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.word = None


class Solution:
    def __init__(self):
        self.root = TrieNode()

    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        for word in dictionary:
            self.insert(word)

        result = []
        for word in sentence.split():
            result.append(self.search(word))

        return " ".join(result)

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            i = ord(c) - ord("a")
            if not node.children[i]:
                node.children[i] = TrieNode()
            node = node.children[i]
        node.word = word

    def search(self, word: str) -> str:
        node = self.root
        for c in word:
            if node.word:
                return node.word
            i = ord(c) - ord("a")
            if not node.children[i]:
                return word
            node = node.children[i]
        return word
