#include <bits/stdc++.h>

int main() {
    std::string input, word, line;
    std::vector<std::string> words;
    std::map<std::string, int> map;

    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        input += line + " ";
    }

    std::stringstream ss(input);

    while (ss >> word) {
        map[word]++;
    }

    int max = 0;

    for (const auto& a : map) {
        max = std::max(max, a.second);
    }

    for (const auto& a : map) {
        if (max == a.second) words.push_back(a.first);
    }

    std::sort(words.begin(), words.end());
    std::cout << words[0] << std::endl;

    return 0;
}

