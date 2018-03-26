#include <iostream>
#include <map>
#include <queue>

class TrieNode {
   public:
    void insert(std::string key) {
        TrieNode* pCrawl = this;

        for (auto c : key) {
            pCrawl->wordCountUnder++;
            if (pCrawl->children.find(c) == pCrawl->children.end()) {
                pCrawl->children[c] = new TrieNode();
            }

            pCrawl = pCrawl->children[c];
        }

        // mark last node as leaf
        pCrawl->isEndOfWord = true;
    }

    int findNum(std::string key) {
        TrieNode* pCrawl = this;

        // Get to the end of the prefix
        for (auto c : key) {
            if (pCrawl->children.find(c) == pCrawl->children.end()) {
                return 0;
            }

            pCrawl = pCrawl->children[c];
        }

        if (pCrawl->isEndOfWord) {
            return pCrawl->wordCountUnder + 1;
        }

        return pCrawl->wordCountUnder;
    }

    TrieNode() {}

   private:
    bool isEndOfWord = false;
    int wordCountUnder = 0;
    std::map<char, TrieNode*> children;
};

int main() {
    TrieNode* root = new TrieNode();
    int n;
    std::cin >> n;
    for (int a0 = 0; a0 < n; a0++) {
        std::string op;
        std::string contact;
        std::cin >> op >> contact;
        if (op == "add") {
            root->insert(contact);
        } else {
            std::cout << root->findNum(contact) << std::endl;
        }
    }
    return 0;
}
