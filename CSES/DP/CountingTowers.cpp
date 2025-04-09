#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9+7;


int main(){
	// n*2
	ll t; std::cin >> t;
	std::vector<std::vector<ll>> dp(1000001, std::vector<ll>(2,0));
	dp[0][0] = 1; dp[0][1] = 1;
	// only orange / only green
	for(int i = 1; i <= 1000000; i++){
		dp[i][0] = (dp[i][0]%MOD+(2*dp[i-1][0])%MOD+dp[i-1][1]%MOD)%MOD;
		dp[i][1] = (dp[i][1]%MOD+(4*dp[i-1][1])%MOD+dp[i-1][0]%MOD)%MOD;
	} 

	for(int i = 0; i < t; i++){
		int curr; std::cin >> curr;
		std::cout << (dp[curr-1][0]+dp[curr-1][1])%MOD << '\n';
	}

}