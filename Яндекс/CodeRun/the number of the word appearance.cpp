#include <bits/stdc++.h>

int main() {
    std::string line, input, word;
    std::vector<std::string> vec;
    std::map<std::string, int> map;

    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        input += line + " ";
    }

    std::stringstream ss(input);

    while (ss >> word) {
        if (map.find(word) == map.end()) {
           vec.push_back("0");
            vec.push_back(" ");
            map[word] = 1;
        } else {
            vec.push_back(std::to_string(map[word]));
            vec.push_back(" ");
            map[word]++;
        }
    }

    for (const auto& a : vec) {
        std::cout << a;
    }

    return 0;
}
