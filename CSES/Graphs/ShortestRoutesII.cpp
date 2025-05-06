#include <bits/stdc++.h>
#define MAXN 500
using ll = long long;
const ll INF = 1e18;

int main(){
	ll n,m,q, a, b,c; std::cin >> n >> m >> q;
	std::vector<std::vector<ll>> grid(MAXN+1, std::vector<ll>(MAXN+1,INF));
	for(int i = 1; i <= n; i++) grid[i][i] = 0;
	for(int i = 0; i < m; i++){
	    std::cin >> a >> b >> c;
	    grid[a][b] = std::min(grid[a][b], c);
	    grid[b][a] = std::min(grid[b][a], c);
	}
	
	for(int k = 1; k <= n; k++){
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= n; j++){
	            grid[i][j] = std::min(grid[i][j], grid[i][k]+grid[k][j]);
	        }
	    }
	}
	
	for(int i = 0; i < q; i++){
	    std::cin >> a >> b;
	    if(grid[a][b] == INF) std::cout << -1 << '\n';
	    else std::cout << grid[a][b] << '\n';
	}
}