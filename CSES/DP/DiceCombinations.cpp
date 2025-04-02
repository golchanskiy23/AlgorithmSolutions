#include <bits/stdc++.h>

using ll = long long;
const ll NUM = 1000001 , MOD = 1e9+7;

int main(){
	ll n; std::cin >> n;
	std::vector<ll> dp(n+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; ++i){
		for(int j = 1; j <= 6; ++j){
			if(i-j >= 0){
				dp[i] += dp[i-j];
				dp[i] %= MOD;
			}
		}
	}
	std::cout << dp[n];
}