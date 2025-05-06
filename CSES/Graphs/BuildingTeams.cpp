#include <bits/stdc++.h>


int main(){
	int n, m, t1, t2; std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n + 1);
	std::vector<int> flags(n+1, -1);
    for (int i = 0; i < m; i++) {
        std::cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

	std::queue<int> q;
	for(int i = 1; i <= n; i++){
	    if(flags[i] == -1){
	        q.push(i);
	        flags[i] = 0;
	        while(!q.empty()){
		        int curr = q.front();
		        q.pop();
		        for (int neighbor : graph[curr]) {
		            if (flags[neighbor] == -1){
		                flags[neighbor] = flags[curr] ^ 1;
		                q.push(neighbor);
		            }
		            if(flags[neighbor] == flags[curr]){
		                std::cout << "IMPOSSIBLE" << '\n';
		                return 0;
		            }
                }
	        }
	    }
	}
	
	for(int i = 1; i <= n; i++){
	    std::cout << flags[i]+1 << " ";
	}
}