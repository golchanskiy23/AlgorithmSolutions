#include <bits/stdc++.h>
using ll = long long;
 
struct DSU{
	std::vector<ll> parents, sizes;
	DSU(int n) : parents(n+1) , sizes(n+1){
		for(int i = 1; i <= n; i++) parents[i] = i;
	}
	int find(int x){
		if(x == parents[x]) return x;
		parents[x] = find(parents[x]);
		return parents[x];
	}
 
	bool unite(int x, int y){
		x = find(x);
		y = find(y);
		if(connected(x,y)){return false;}
		if(sizes[x] < sizes[y]) std::swap(x,y);
		sizes[x] += sizes[y];
		parents[y] = x;
		return true;
	}
	bool connected(int x, int y){
		return find(x) == find(y);
	}
};
 
struct Road{
	int a,b,c;
	Road(int a1, int b1, int c1){
		a = a1;
		b = b1;
		c = c1;
	}
};
 
int main(){
	int n,m,a,b,c; std::cin >> n >> m;
	auto dsu = DSU(n);
	std::vector<Road> roads;
	for(int i = 0; i < m; i++){
		std::cin >> a >> b >> c;
		roads.push_back(Road(a,b,c));
	}
	std::sort(roads.begin(), roads.end(), [](const Road& r1, const Road& r2){
		return r1.c < r2.c;
	});
	
	ll minCost = 0, added = 0;
	for(int i = 0; i < m; i++){
		// if not in one union -> true, status = 1
		int status = dsu.unite(roads[i].a, roads[i].b);
		added += status;
		minCost += status*roads[i].c;
	}
	if(added != n-1){std::cout << "IMPOSSIBLE";}
	else{std::cout << minCost;}
}
