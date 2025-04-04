#include <bits/stdc++.h>
using ll = long long;
 
const ll MOD = 1e9 + 7;
 
int main() {
	int n, x; std::cin >> n >> x;
	std::vector<int> coins(n), dp(x + 1, 0);
	for (auto &x : coins) { std::cin >> x; }
 
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for(int j = coins[i]; j <= x; ++j){
			if(j-coins[i] >= 0){
				dp[j] += dp[j-coins[i]];
				dp[j] %= MOD;
			}
		}
	}
 
	std::cout << dp[x] << '\n';
}