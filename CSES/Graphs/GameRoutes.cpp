#include <bits/stdc++.h>
const int MOD = 1e9+7;

void dfs(int node, std::vector<bool>& v,const std::vector<std::vector<int>>& adjList){
    v[node] = true;
    for(auto& a : adjList[node]){
        if (!v[a]) dfs(a, v, adjList);
    }
}

int main(){
	int n,m,a,b; std::cin >> n >> m;
	std::vector<std::vector<int>> adjList(n+1), reversedAdjList(n+1);
	std::vector<int> inDegree(n+1, 0), dp(n+1, 0);
	std::vector<bool> isReachable1_n(n+1, false), isReachablen_1(n+1, false);
	for(int i = 0; i < m; i++){
	    std::cin >> a >> b;
	    inDegree[b]++;
	    adjList[a].push_back(b);
	    reversedAdjList[b].push_back(a);
	}
	
    dfs(1, isReachable1_n, adjList);
    dfs(n, isReachablen_1, reversedAdjList);
    
    std::queue<int> q;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    dp[1] = 1;
    while(!q.empty()){
        auto head = q.front();
        q.pop();
        for(auto& a : adjList[head]){
            inDegree[a]--;
            if(inDegree[a] == 0) q.push(a);
            if(isReachable1_n[head] && isReachablen_1[a]) {
                dp[a] += dp[head];
                dp[a] %= MOD;
	    }
        }
    }
    
    std::cout << dp[n];
}