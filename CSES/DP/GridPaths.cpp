#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9+7;

int Paths(int n){
	std::vector<std::string> grid(n);
	std::vector<std::vector<ll>> dp(n, std::vector<ll>(n,0));
	
	for(int i = 0; i < n; ++i) std::cin >> grid[i];
	if (grid[0][0] == '*') return 0;
	dp[0][0] = 1;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if (grid[i][j] == '.'){
				if(i-1 >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
				if(j-1 >= 0) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
			}	
		}
	}
	return dp[n-1][n-1];
}

int main(){
	ll n; std::cin >> n;
	std::cout << Paths(n);
}