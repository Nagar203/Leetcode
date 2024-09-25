#include <unordered_set>
#include <vector>

struct TrieNode {
    TrieNode* children[26] = {};  // Array of TrieNode pointers for 26 lowercase letters
    int prefixCount = 0;  // Keeps track of prefix count
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> prefixScores;
        TrieNode* root = new TrieNode();

        // Insert all words into the Trie
        for (const string& word : words) {
            insertWord(word, root);
        }

        // Calculate prefix scores for all words
        for (const string& word : words) {
            prefixScores.push_back(calculatePrefixScore(word, root));
        }

        // Clean up dynamically allocated Trie nodes
        deleteTrie(root);

        return prefixScores;
    }

private:
    // Inserts a word into the Trie
    void insertWord(const string& word, TrieNode* root) {
        TrieNode* currentNode = root;
        for (const char character : word) {
            int index = character - 'a';
            if (!currentNode->children[index]) {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
            currentNode->prefixCount += 1;
        }
    }

    // Calculates the score for the given word based on the Trie
    int calculatePrefixScore(const string& word, TrieNode* root) {
        TrieNode* currentNode = root;
        int totalScore = 0;
        for (const char character : word) {
            currentNode = currentNode->children[character - 'a'];
            totalScore += currentNode->prefixCount;
        }
        return totalScore;
    }

    // Recursively delete all Trie nodes to free up memory
    void deleteTrie(TrieNode* node) {
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                deleteTrie(node->children[i]);
            }
        }
        delete node;
    }
};