#include <bits/stdc++.h>
using ll = long long;

struct DSU {
    std::vector<int> parents, sizes;
    DSU(int n) : parents(n+1), sizes(n+1, 1) {
        for (int i = 1; i <= n; i++) parents[i] = i;
    }
    int find(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sizes[x] < sizes[y]) std::swap(x, y);
        sizes[x] += sizes[y];
        parents[y] = x;
        return true;
    }
};

int main() {
    int n, m; 
    std::cin >> n >> m;
    DSU dsu(n);

    ll numberComponents = n;
    int largest = 1;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        if (dsu.unite(a, b)) {
            numberComponents--;
            int root = dsu.find(a);
            if (dsu.sizes[root] > largest) {
                largest = dsu.sizes[root];
            }
        }
        std::cout << numberComponents << " " << largest << "\n";
    }
    return 0;
}