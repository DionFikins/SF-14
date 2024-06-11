#include "TrieNode.h"

TrieNode* getNewNode(void)
{
    struct TrieNode* Node = new TrieNode;

    Node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node->children[i] = nullptr;
    }

    return Node;
}

void insert(TrieNode* root, std::string key)
{
    TrieNode* node = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if (!node->children[index]) {
            node->children[index] = getNewNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool search(TrieNode* root, std::string key)
{
    TrieNode* node = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return (node != nullptr && node->isEndOfWord);
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            return false;
        }
    }
    return true;
}

TrieNode* remove(TrieNode* root, std::string key, int depth)
{
    if (!root) {
        return nullptr;
    }
    if (depth == key.size()) {
        if (root->isEndOfWord) {
            root->isEndOfWord = false;
        }
        if (isEmpty(root)) {
            delete(root);
            root = nullptr;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);
    if (isEmpty(root) && root->isEndOfWord == false) {
        delete(root);
        root = nullptr;
    }
    return root;
}

bool word(std::string& prefix, std::string& end)
{
    int count = 0;
    int length = 0;

    int lengthPref = prefix.size();
    int lengthEnd = end.size();

    if (lengthPref <= lengthEnd) {
        length = lengthPref;
    }
    else {
        length = lengthEnd;
    }

    for (int i = 0; i < length; ++i) {
        if (prefix[i] == end[i]) {
            ++count;
        }
    }

    return count == length;
}

void complited(TrieNode* root, std::string& prefix, std::string end)
{
    TrieNode* node = root;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            end.push_back(i + 'a');
            if (node->children[i]->isEndOfWord) {
                if (word(prefix, end)) {
                    std::cout << end << std::endl;
                }
            }
            complited(node->children[i], prefix, end);
            end.pop_back();
        }
    }
}