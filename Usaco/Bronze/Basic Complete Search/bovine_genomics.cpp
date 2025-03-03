#include <bits/stdc++.h>

int main(){
    std::ifstream in("cownomics.in");
    std::ofstream out("cownomics.out");
    int n,m; in >> n >> m;
    std::vector<std::string> spotted(n), unspotted(n);
    for (int i = 0; i < n; ++i) in >> spotted[i];
    for (int i = 0; i < n; ++i) in >> unspotted[i];

    std::vector<std::set<char>> s(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s[j].insert(spotted[i][j]);
        }
    }

    std::vector<std::set<char>> us(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            us[j].insert(unspotted[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        bool flag = true;
        for (auto& a : us[i]) {
            if (s[i].count(a) != 0) {
                flag = false;
                break;
            }
        }
        if (flag) ++ans;
    }
    out << ans;
}