# SF-14

TrieNode.h<br>
```C++
struct TrieNode { // структура взята с материалов курса
  struct TrieNode* children[ALPHABET_SIZE];
  bool isEndOfWord;
};

TrieNode* getNewNode(void); // взято с материала курса

void insert(TrieNode* root, std::string key); // с практического задания

bool search(struct TrieNode* root, std::string key); // взято с материала курса
bool isEmpty(TrieNode* root); // взято с материала курса

TrieNode* remove(TrieNode* root, std::string key, int depth = 0); // взято с материала курса

bool word(std::string& prefix, std::string& end); // отвечает за проверку нахождения
bool complited(TrieNode* root, std::string& prefix, std::string end); // отвечает за отображение всех найденых и показывает, какие можно взять, как в Т9
```
