#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> intersection(set<pair<int, int>>& s1, set<pair<int, int>>& s2) {
    set<pair<int, int>> s;
    for (auto& a : s1) {
        if (s2.count(a) != 0) s.insert(a);
    }
    return s;
}

int main() {
    std::ifstream in("gymnastics.in");
    std::ofstream out("gymnastics.out");
    int k, n;
    in >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> v[i][j];
        }
    }

    set<pair<int, int>> s;
    for (int j = 0; j < n; ++j) {
        for (int l = j + 1; l < n; ++l) {
            s.insert({v[0][j], v[0][l]});
        }
    }

    for (int i = 1; i < k; ++i) {
        set<pair<int, int>> tmp;
        for (int j = 0; j < n; ++j) {
            for (int l = j + 1; l < n; ++l) {
                tmp.insert({v[i][j], v[i][l]});
            }
        }
        s = intersection(s, tmp);
    }

    out << s.size() << endl;
    return 0;
}
