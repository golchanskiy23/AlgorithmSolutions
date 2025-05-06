#include <bits/stdc++.h>

struct DSU{
	std::vector<int> parent, rank;
	int connComponentsNum;
	DSU(int n) : parent(n+1), rank(n+1,1), connComponentsNum(n) {
		for(int i = 1; i <= n; i++) parent[i] = i;
	}
	
	int find(int x){
		if(parent[x] != x){
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unite(int a, int b){
		a = find(a);
		b = find(b);
		if(!same(a,b)){
			connComponentsNum--;
			if(rank[a] < rank[b]) std::swap(a,b);
			parent[b] = a;
			if(rank[a] == rank[b]) rank[a]++;
		}
	}

	bool same(int a, int b){
		return a == b;
	}
};

int main(){
	int n,m; std::cin >> n >> m;
	DSU dsu(n);
	int t1, t2;
	for(int i = 0; i < m; i++){
		std::cin >> t1 >> t2;
		dsu.unite(t1, t2);
	}
	std::cout << dsu.connComponentsNum-1 << '\n';
	if(dsu.connComponentsNum == 1) return 0;
	std::set<int> s;
	for(int i = 1; i <= n; i++){
		s.insert(dsu.find(i));
	}

	auto prev = s.begin();
 	auto curr = std::next(s.begin());

    	while (curr != s.end()) {
        	std::cout << *prev << " " << *curr << std::endl;
        	++prev;
        	++curr;
    	}
}