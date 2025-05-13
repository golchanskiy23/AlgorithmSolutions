#include <bits/stdc++.h>
#define f first
#define s second

using ll = long long;
using pii = std::pair<ll, ll>;

const ll MAX = 1e18;

std::vector<ll> minCost(int startNode, std::vector<std::vector<pii>> v, int n){
	std::vector<ll> distance(n+1, MAX);
	distance[startNode] = 0;
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
	// cost / node
	q.push({0,startNode});
	while(!q.empty()){
	    auto curr = q.top();
	    q.pop();
	    ll cost = curr.f, node = curr.s;
	    if(cost != distance[node]){continue;}
	    
	    for(auto& el : v[node]){
	        ll newCost = distance[node]+el.s;
	        if(newCost < distance[el.f]){
	            distance[el.f] = newCost;
	            q.push({newCost, el.f});
	        }
	    }
	}
	
	return distance;
}

int main() {
    ll n, m, c, d, e;
    std::cin >> n >> m;
    std::vector<std::vector<pii>> directed(n + 1), reversed(n + 1);
    for (int i = 0; i < m; i++) {
        std::cin >> c >> d >> e;
        directed[c].push_back({d, e});
        reversed[d].push_back({c, e});
    }

    std::vector<ll> minCostFromStart = minCost(1, directed, n);
    std::vector<ll> minCostToEnd = minCost(n, reversed, n);

    ll ans = MAX;
    for (int u = 1; u <= n; ++u) {
        for (auto& [v, w] : directed[u]) {
            if (minCostFromStart[u] == MAX || minCostToEnd[v] == MAX) continue;
            ans = std::min(ans, minCostFromStart[u] + w / 2 + minCostToEnd[v]);
        }
    }

    std::cout << ans << "\n";
}