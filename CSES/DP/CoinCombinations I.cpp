#include <bits/stdc++.h>
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	int n, x; std::cin >> n >> x;
	std::vector<int> coins(n), dp(x + 1);
	for (auto &x : coins) { std::cin >> x; }

	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for(int j = 0; j < n; ++j){
			if(i-coins[j] >= 0){
				dp[i] += dp[i-coins[j]];
				dp[i] %= MOD;
			}
		}
	}

	std::cout << dp[x] << '\n';
}