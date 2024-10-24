#include <bits/stdc++.h>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::unordered_map<int, std::vector<int>> positions;
    for (int i = 0; i < n; ++i) {
        positions[a[i]].push_back(i);
    }

    int total_changes = n;  // Изначально предполагаем, что все элементы нужно изменить

    for (const auto& entry : positions) {
        const std::vector<int>& pos = entry.second;
        int changes = 0;
        for (int i = 1; i < pos.size(); ++i) {
            if (pos[i] != pos[i - 1] + 1) {
                changes++;
            }
        }
        total_changes = std::min(total_changes, changes);
    }

    std::cout << total_changes + 1 << std::endl;  // Добавляем 1 для учета начального изменения

    return 0;
}

