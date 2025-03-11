#include <bits/stdc++.h>

int main() {
    int g, S;
    std::cin >> g >> S;
    std::string W, S_str;
    std::cin >> W >> S_str;

    if (g > S) {
        std::cout << 0 << '\n';
        return 0;
    }

    std::array<int, 128> idealFreq{}, windowFreq{};
    
    for (char c : W) idealFreq[c]++;
    int matchCount = 0, matches = 0;

    for (int i = 0; i < g; i++) {
        char c = S_str[i];
        windowFreq[c]++;
        if (windowFreq[c] == idealFreq[c]) matches++;
        else if (windowFreq[c] == idealFreq[c] + 1) matches--;
    }
    
    int size = std::count_if(idealFreq.begin(), idealFreq.end(), [](int x) { return x > 0; });

    if (matches == size) {
        matchCount++;
    }

    for (int i = g; i < S; i++) {
        char newChar = S_str[i], oldChar = S_str[i - g];

        windowFreq[newChar]++;
        if (windowFreq[newChar] == idealFreq[newChar]) matches++;
        else if (windowFreq[newChar] == idealFreq[newChar] + 1) matches--;

        windowFreq[oldChar]--;
        if (windowFreq[oldChar] == idealFreq[oldChar]) matches++;
        else if (windowFreq[oldChar] == idealFreq[oldChar] - 1) matches--;

        if (matches == size) {
            matchCount++;
        }
    }

    std::cout << matchCount << '\n';
    return 0;
}