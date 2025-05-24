#include <bits/stdc++.h>
const int MAXN = 200000;

std::vector<bool> visited(MAXN+1, false);
std::vector<int> destinations(MAXN+1, 0), ans(MAXN+1, 0);
std::queue<int> q;
int steps = 0;

void dfs(int i){
	q.push(i);
	if(visited[i]){
		steps += ans[i];
		return;
	}
	visited[i] = true;
	steps++;
	dfs(destinations[i]);	
}

int main(){
	int n, a; std::cin >> n;
	for(int i = 1;i <= n; i++){
		std::cin >> a;
		destinations[i] = a;
	}

	for(int i = 1; i <= n; i++){
		steps = 0;
		dfs(i);
		// get number of steps
		int errorRate = 1;
		while(!q.empty()){
			int f = q.front(), b = q.back();
			if(f == b) errorRate = 0;
			ans[f] = steps;
			steps -= errorRate;
			q.pop();
		}
	}
	for(int i = 1; i <= n; i++) std::cout << ans[i] << " ";
	
}