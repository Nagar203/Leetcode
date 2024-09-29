#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node {
    int count;
    unordered_set<string> keys;
};

class AllOne {
public:
    // Increment the count of the given key
    void inc(string key) {
        if (const auto keyIterator = keyToNode.find(key); keyIterator == keyToNode.end()) {
            addNewKey(key);
        } else {
            incrementExistingKey(keyIterator, key);
        }
    }

    // Decrement the count of the given key
    void dec(string key) {
        const auto keyIterator = keyToNode.find(key);
        decrementExistingKey(keyIterator, key);
    }

    // Return the key with the maximum count
    string getMaxKey() {
        return nodeList.empty() ? "" : *nodeList.back().keys.begin();
    }

    // Return the key with the minimum count
    string getMinKey() {
        return nodeList.empty() ? "" : *nodeList.front().keys.begin();
    }

private:
    list<Node> nodeList;  // List of nodes sorted by count
    unordered_map<string, list<Node>::iterator> keyToNode;

    // Add a new key with count 1
    void addNewKey(const string& key) {
        if (nodeList.empty() || nodeList.front().count > 1) {
            nodeList.push_front({1, {key}});
        } else {
            nodeList.front().keys.insert(key);
        }
        keyToNode[key] = nodeList.begin();
    }

    // Increment the count of an existing key
    void incrementExistingKey(
        unordered_map<string, list<Node>::iterator>::iterator keyIterator,
        const string& key) {
        const auto currentNode = keyIterator->second;
        auto nextNode = next(currentNode);
        const int newCount = currentNode->count + 1;

        if (nextNode == nodeList.end() || nextNode->count > newCount) {
            nextNode = nodeList.insert(nextNode, {newCount, {key}});
        } else {
            nextNode->keys.insert(key);
        }

        keyToNode[key] = nextNode;
        removeKeyFromNode(currentNode, key);
    }

    // Decrement the count of an existing key
    void decrementExistingKey(
        unordered_map<string, list<Node>::iterator>::iterator keyIterator,
        const string& key) {
        const auto currentNode = keyIterator->second;

        if (currentNode->count == 1) {
            keyToNode.erase(keyIterator);
            removeKeyFromNode(currentNode, key);
            return;
        }

        auto previousNode = prev(currentNode);
        const int newCount = currentNode->count - 1;

        if (currentNode == nodeList.begin() || previousNode->count < newCount) {
            previousNode = nodeList.insert(currentNode, {newCount, {key}});
        } else {
            previousNode->keys.insert(key);
        }

        keyToNode[key] = previousNode;
        removeKeyFromNode(currentNode, key);
    }

    // Remove the key from the node, and erase the node if empty
    void removeKeyFromNode(list<Node>::iterator node, const string& key) {
        node->keys.erase(key);
        if (node->keys.empty()) {
            nodeList.erase(node);
        }
    }
};