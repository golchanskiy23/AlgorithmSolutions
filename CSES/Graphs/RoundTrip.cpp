#include <bits/stdc++.h>
#define MAXN 100000

std::vector<std::vector<int>> graph(MAXN);
std::vector<bool> visited(MAXN, false);
std::vector<int> parent(MAXN, -1);
int startCycle = -1, endCycle = -1;

bool dfs(int node, int par){
	visited[node] = true;
	for(int neighbour : graph[node]){
		if(par == neighbour) continue;
		if(visited[neighbour]){
			endCycle = node;
			startCycle = neighbour;
			return true;
		}
		parent[neighbour] = node;
		if(dfs(neighbour, node)) return true;
	}
	return false;
}

int main(){
	int n,m, u,v; std::cin >> n >> m;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			if(dfs(i,-1)){
				std::vector<int> ans;
				ans.push_back(startCycle);
				while(endCycle != startCycle){
					ans.push_back(endCycle);
					endCycle = parent[endCycle];
				}
				ans.push_back(startCycle);
				if(ans.size() < 4) continue;
				std::cout << ans.size() << '\n';
				std::reverse(ans.begin(), ans.end());
				for(auto& a : ans) std::cout << a << " ";
				return 0;
			}
		}
	}
	std::cout << "IMPOSSIBLE";
}