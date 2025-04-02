#include <bits/stdc++.h>

using ll = long long;

int main(){
	int n,x; std::cin >> n >> x;
	std::vector<ll> v(n), dp(1000001, INT_MAX);
	for(int i = 0; i < n; ++i) std::cin >> v[i];
	dp[0] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = v[i-1]; j <= x; j++){
			dp[j] = std::min(dp[j], dp[j-v[i-1]]+1);
		}
	}
	ll ans = (dp[x] == INT_MAX) ? -1 : dp[x];
	std::cout << ans;
}