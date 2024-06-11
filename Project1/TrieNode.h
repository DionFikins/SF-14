#pragma once
#ifndef TRIE_NODE
#define TRIE_NODE
#include <iostream>
#define ALPHABET_SIZE 26

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TrieNode* getNewNode(void);

void insert(TrieNode* root, std::string key);

bool search(struct TrieNode* root, std::string key);
bool isEmpty(TrieNode* root);

TrieNode* remove(TrieNode* root, std::string key, int depth = 0);

bool word(std::string& prefix, std::string& end);

void complited(TrieNode* root, std::string& prefix, std::string end);

#endif // !TRIE_NODE