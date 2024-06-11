#include <iostream>
#include <Windows.h>
#include "TrieNode.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TrieNode* root = getNewNode();

	insert(root, "fd");
	insert(root, "frqw");
	insert(root, "fges");

	insert(root, "dma");
	insert(root, "der");
	insert(root, "dqw");

	std::string str;
	while (str != "q") {
		std::cout << "enter word: " << std::endl;
		std::cin >> str;
		if (str == "q") continue;

		std::cout << "word: " << std::endl;
		complited(root, str, "");
	}
	delete root;
}