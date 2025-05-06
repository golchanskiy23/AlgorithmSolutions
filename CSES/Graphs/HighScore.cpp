#include <bits/stdc++.h>
using ll = long long;

const ll INF = 1e18;

struct Edge {
    int a, b;
    ll weight;
};

int n, m;

void dfs(int v, std::vector<bool>& visited, const std::vector<std::vector<int>>& graph) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) dfs(u, visited, graph);
    }
}

int main() {
    std::cin >> n >> m;
    std::vector<Edge> edges;
    std::vector<std::vector<int>> g(n+1), g_rev(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        std::cin >> u >> v >> w;
        edges.push_back({u, v, w});
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }

    std::vector<bool> reachable_from_1(n + 1, false), reachable_to_n(n + 1, false);
    dfs(1, reachable_from_1, g);
    dfs(n, reachable_to_n, g_rev);

    std::vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            if (dist[e.a] != -INF && dist[e.a] + e.weight > dist[e.b]) {
                dist[e.b] = dist[e.a] + e.weight;
            }
        }
    }

    for (auto e : edges) {
        if (dist[e.a] != -INF && dist[e.a] + e.weight > dist[e.b]) {
            if (reachable_from_1[e.a] && reachable_to_n[e.b]) {
                std::cout << -1 << '\n';
                return 0;
            }
        }
    }

    if (dist[n] == -INF) std::cout << -1 << '\n';
    else std::cout << dist[n] << '\n';
    
    return 0;
}

