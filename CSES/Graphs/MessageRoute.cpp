#include <bits/stdc++.h>

int main(){
	int n, m, t1, t2; std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n + 1);
    	std::vector<int> parent(n + 1, 0), distance(n + 1, INT_MAX);

    	for (int i = 0; i < m; i++) {
        	std::cin >> t1 >> t2;
        	graph[t1].push_back(t2);
        	graph[t2].push_back(t1);
    	}

	std::queue<int> q;
	q.push(1);
	distance[1] = 0;
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for (int neighbor : graph[curr]) {
            		if (distance[neighbor] == INT_MAX) {
                		distance[neighbor] = distance[curr] + 1;
                		parent[neighbor] = curr;
                		q.push(neighbor);
            		}
        	}
	}
	if(distance[n] == INT_MAX){
		std::cout << "IMPOSSIBLE" << '\n';
	}
	else{
		std::cout << distance[n]+1 << '\n';
		std::vector<int> ans;
		while(parent[n] != 0){
			ans.push_back(n);
			n = parent[n];
		}
		ans.push_back(1);
		std::reverse(ans.begin(), ans.end());
		for(auto& a : ans) std::cout << a << " ";
	}
}