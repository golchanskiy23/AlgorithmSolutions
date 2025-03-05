#include <iostream>

#include "Trie.h"

int main() {
    stringStructures::Trie prefixTree;
    prefixTree.add("sas");
    prefixTree.add("sass");
    prefixTree.add("sabs");
    prefixTree.add("sbas");
    if (prefixTree.find("sas") && prefixTree.find("sass")) std::cout << "It found" << '\n';
    prefixTree.print();
    prefixTree.erase("sass");
    prefixTree.print();
    return 0;
}