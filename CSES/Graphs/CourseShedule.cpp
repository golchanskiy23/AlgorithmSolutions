#include <bits/stdc++.h>

std::vector<int> topologicSort(const std::vector<std::vector<int>>& adjList, std::vector<int>& inDegree, int n){
    std::vector<int> ans;
    std::queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        auto head = q.front();
        q.pop();
        ans.push_back(head);
        for(auto& a : adjList[head]){
            inDegree[a]--;
            if(inDegree[a] == 0) q.push(a);
        }
    }
    if(ans.size() < n) return std::vector<int>{};
    return ans;
}

int main() {
	int n, m, a, b;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adjList(n+1);
	std::vector<int> inDegree(n+1, 0);
	for(int i = 0; i < m; i++){
		std::cin >> a >> b;
		adjList[a].push_back(b);
		inDegree[b]++;
	}
	
	auto ans =  topologicSort(adjList, inDegree, n);
	if(ans.size() == 0) {
	    std::cout << "IMPOSSIBLE" << '\n';
	    return 0;
	}
	for(auto& a : ans) std::cout << a << " "; 
}