#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  TrieNode() : children(10) {}  // Initializes children for digits 0-9
};

class Trie {
 public:
  // Insert a number string into the Trie
  void insert(const string& numberString) {
    shared_ptr<TrieNode> currentNode = root;
    for (const char digit : numberString) {
      const int index = digit - '0';  // Convert character to corresponding index
      if (currentNode->children[index] == nullptr)
        currentNode->children[index] = make_shared<TrieNode>();
      currentNode = currentNode->children[index];
    }
  }

  // Search for the longest common prefix of a number string
  int search(const string& numberString) {
    int commonPrefixLength = 0;
    shared_ptr<TrieNode> currentNode = root;
    for (const char digit : numberString) {
      const int index = digit - '0';
      if (currentNode->children[index] == nullptr)
        break;
      currentNode = currentNode->children[index];
      ++commonPrefixLength;
    }
    return commonPrefixLength;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();  // Root of the Trie
};

class Solution {
 public:
  // Function to find the longest common prefix between two arrays of integers
  int longestCommonPrefix(vector<int>& array1, vector<int>& array2) {
    int maxPrefixLength = 0;
    Trie trie;

    // Insert all numbers from array1 into the Trie
    for (const int number : array1)
      trie.insert(to_string(number));

    // Search for the longest common prefix with numbers in array2
    for (const int number : array2)
      maxPrefixLength = max(maxPrefixLength, trie.search(to_string(number)));

    return maxPrefixLength;
  }
};