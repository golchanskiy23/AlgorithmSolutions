#include <bits/stdc++.h>

using ll = long long;
const ll MOD = 1e9+7;

int main(){
	ll n,m; std::cin >> n >> m;
	std::vector<ll> v(n);
	for(int i = 0; i < n; i++) std::cin >> v[i];

	std::vector<std::vector<ll>> dp(n, std::vector<ll>(m+2, 0));

	if(v[0] == 0) {
		for(int i =1; i <= m; i++) {dp[0][i] = 1;}
	} else {dp[0][v[0]] = 1;}

	for(int i = 1; i < n; i++){
		if (v[i] == 0) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] += (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]);
				dp[i][j] %= MOD;
			}
		} else {
			dp[i][v[i]] += (dp[i - 1][v[i]] + dp[i - 1][v[i] - 1] + dp[i - 1][v[i] + 1]);
			dp[i][v[i]] %= MOD;
		}
	}
	
	ll ans = 0;
	for(int i = 0; i <= m+1; i++){
	    ans += dp[n-1][i];
	    ans %= MOD;
	}
	std::cout << ans;
}