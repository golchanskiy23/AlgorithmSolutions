#include <bits/stdc++.h>

bool dfs(int v, std::vector<int>& color, const std::vector<std::vector<int>>& adjList, int& cycleEnd, int& cycleBegin, std::vector<int>& parent){
	color[v] = 1;
	for (auto& u : adjList[v]) {
            if (color[u] == 1) {
            	parent[u] = v;
            	cycleEnd = v;
            	cycleBegin = u;
           	return true;
            }
            if (color[u] == 0) {
            	parent[u] = v;
            	if (dfs(u, color, adjList, cycleEnd, cycleBegin, parent)) {
                	return true;
            	}
            }
    	}
	color[v] = 2;
	return false;
}

int main() {
	int n, m, a, b, cycleEnd=-1, cycleBegin = -1;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adjList(n+1);
	for(int i = 0; i < m; i++){
		std::cin >> a >> b;
		adjList[a].push_back(b);
	}
	
	std::vector<int> color(n+1, 0), parent(n+1, -1);
	for(int i = 1;i <= n; i++){
		if(color[i] == 0 && dfs(i, color, adjList, cycleEnd, cycleBegin, parent)){
			std::vector<int> v;
			v.push_back(cycleBegin);
			for(int i = cycleEnd; i != cycleBegin; i = parent[i]){
				v.push_back(i);
			}
			v.push_back(cycleBegin);
			std::reverse(v.begin(), v.end());
			std::cout << v.size() << '\n';
			for(auto& a : v) std::cout << a << " ";
			return 0;
		}
	}

	std::cout << "IMPOSSIBLE" << '\n';
}