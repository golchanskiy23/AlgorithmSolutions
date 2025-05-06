#include <bits/stdc++.h>
#define f first
#define s second 

using vvpii = std::vector<std::vector<std::pair<int, int>>>;
using p = std::pair<long long, int>;

int main() {
	int n, m, a, b, c; std::cin >> n >> m;
	vvpii neighbors(n);
	for (int i = 0; i < m; i++) {
		std::cin >> a >> b >> c;
		neighbors[a - 1].push_back({b - 1, c});
	}

	std::vector<long long> dist(n, LLONG_MAX);
	std::priority_queue<p, std::vector<p>, std::greater<p>> pq;

	int start = 0;
	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		auto head = pq.top();
		pq.pop();
		if (head.f != dist[head.s]) continue;
		for (const std::pair<int, int> &i : neighbors[head.s]) {
			if (head.f + i.s < dist[i.f]) {
				pq.push({dist[i.f] = head.f + i.s, i.f});
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { std::cout << dist[i] << ' '; }
	std::cout << dist[n - 1] << '\n';
}