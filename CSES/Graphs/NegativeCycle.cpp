#include <bits/stdc++.h>
#define f first
#define s second

using ll = long long;
const ll MIN = -1e18;

struct Edge{
	ll a,b,c;
};

int main(){
	ll n,m,a,b,c,x; std::cin >> n >> m;
	std::vector<Edge> edges;
	std::vector<ll> parent(n+1, -1), distance(n+1, 0); 
	for(int i = 0; i < m; i++){
		std::cin >> a >> b >> c;
		edges.push_back({a,b,c});
	}

	// Bellman-Ford
	for(int i = 0; i < n; i++){
		x = -1;
		for(auto& e : edges){
			if(distance[e.a]+e.c < distance[e.b]){
				distance[e.b] = std::min(MIN, distance[e.a]+e.c);
				parent[e.b] = e.a;
				x = e.b;
			}
		}
	}
	
	if(x == -1){std::cout << "NO" << '\n';}
	else{
	    std::cout << "YES" << '\n';
	    for(int i = 0; i < n; i++) x = parent[x];
	    std::vector<ll> v;
	    v.push_back(x);
	    for(int i = parent[x]; ;i=parent[i]){
	        v.push_back(i);
	        if(i == x) break;
	    }
	    std::reverse(v.begin(), v.end());
	    for(auto& a : v) std::cout << a << " ";
	}
}