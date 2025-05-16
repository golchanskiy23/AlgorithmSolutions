#include <bits/stdc++.h>
void dfs(int node, std::vector<bool>& v,const std::vector<std::vector<int>>& adjList){
    v[node] = true;
    for(auto& a : adjList[node]){
        if (!v[a]) dfs(a, v, adjList);
    }
}

int main(){
	int n,m,a,b; std::cin >> n >> m;
	std::vector<std::vector<int>> adjList(n+1);
	std::vector<int> inDegree(n+1, 0), dist(n+1, 0), parent(n+1, -1);
	std::vector<bool> isReachable(n+1, false);
    for(int i = 0; i < m; i++){
        std::cin >> a >> b;
        adjList[a].push_back(b);
        inDegree[b]++;
    }
    isReachable[1] = true;
    dfs(1, isReachable, adjList);
    if(isReachable[n] == false){
        std::cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    // topologic sort
    std::queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) { 
		    q.push(i); 
		    //dist[i] = 1;
		}
	}
	dist[1] = 1;
	while(!q.empty()){
        auto head = q.front();
        q.pop();
        for(auto& a : adjList[head]){
            inDegree[a]--;
            if(inDegree[a] == 0) q.push(a);
            if(isReachable[head]) {
                if (dist[a] < dist[head] + 1) {
    			dist[a] = dist[head] + 1;
    			parent[a] = head;
		}
            }
        }
    }
    
    if(parent[n] == -1){
        std::cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    
    std::vector<int> ans;
    int x = n;
    while(x != -1){
        ans.push_back(x);
        x = parent[x];
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for(auto& a : ans) std::cout << a << " ";
}