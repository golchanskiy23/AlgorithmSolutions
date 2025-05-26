#include <bits/stdc++.h>

const int N = 1e5 + 1;

std::vector<int> adj[N], rev[N];
std::stack<int> order;
std::vector<int> id(N);
std::vector<bool> vis(N);

void dfs1(int v) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (!vis[u]) { dfs1(u); }
	}
	order.push(v);
}

void dfs2(int x, int comp) {
	vis[x] = true;
	for (int u : rev[x]) {
		if (!vis[u]) { dfs2(u, comp); }
	}
	id[x] = comp;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}

	vis.assign(N, false);

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) { dfs1(i); }
	}

	vis.assign(N, false);
	int comps = 0;
	while(!order.empty()){
		auto head = order.top();
		if (!vis[head]) {
			comps++;
			dfs2(head, comps);
		}
		order.pop();
	}

	std::cout << comps << '\n';

	for (int i = 1; i <= n; i++) { std::cout << id[i] << " "; }
}