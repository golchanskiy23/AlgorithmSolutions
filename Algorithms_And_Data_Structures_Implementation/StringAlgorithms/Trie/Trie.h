#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

namespace stringStructures {
    class Trie {
    public:
        struct TrieNode {
            char value;
            int neighbours;
            TrieNode* to[26];
            bool isTerminal;
            TrieNode() : value(' '), neighbours(0), to(nullptr), isTerminal(false){}
            TrieNode(const char& symbol) : value(symbol), to(nullptr), isTerminal(false){}
            ~TrieNode() {
                delete [] to;
            }
        };

        Trie() : numberOfWords(0), root(nullptr){}

        void add(const std::string& str) {
            if (str.empty()) return;
            TrieNode* v;
            if (root == nullptr) {
                root = new TrieNode();
            }
            v = root;
            for (char c : str) {
                c -= 'a';
                if (!v->to[c]) {
                    v->to[c] = new TrieNode();
                    numberOfWords++;
                }
                v = v->to[c];
                v->neighbours++;
            }
            v->isTerminal = true;
        }

        bool find(const std::string& str) {
            if (root == nullptr) {
                return false;
            }
            TrieNode* v = root;
            for (char c : str) {
                if (!v->to[c-'a']) {
                    return false;
                }
                v = v->to[c-'a'];
            }
            return v->isTerminal;
        }

        // +LCA: двигаемся вверх, пока не будет минимум 2 соседа или не дойдём до корня
        // ошибка по памяти
        void erase(const std::string& str) {
            if (root == nullptr) return;
            if (!find(str)) return;
            TrieNode* v = root;

            std::vector<TrieNode*> nodeVector;
            for (char c : str) {
                nodeVector.push_back(v);
                v = v->to[c-'a'];
            }
            v->isTerminal = false;
            for (size_t i = nodeVector.size()-1; i >= 0; --i) {
                TrieNode* parent = nodeVector[i];
                if (parent == root) return;

                if (parent->neighbours >= 1) {
                    parent->neighbours--;
                    if (parent->neighbours == 1) return;
                }
                if (parent->neighbours == 0) delete parent;
            }
        }

        void print() {
            if (root == nullptr) return;
            printHelper(root, "");
        }
    private:
        size_t numberOfWords;
        TrieNode* root;

        void printHelper(TrieNode* node, std::string str) {
            if (node == nullptr) return;
            if (node->isTerminal) {
                std::cout << str << '\n';
            }

            for (int i = 0; i < 26; ++i) {
                if (node->to[i]) {
                    printHelper(node->to[i], str+char('a'+i));
                }
            }
        }
    };
}

#endif
