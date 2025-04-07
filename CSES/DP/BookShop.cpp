#include <bits/stdc++.h>
using ll = long long;

int main(){
	ll n,x; std::cin >> n >> x;
	std::vector<ll> price(n), pages(n);
	std::vector<ll> dp(x+1,0);
	for(int i = 0; i <n; i++) std::cin >> price[i];
	for(int i = 0; i <n; i++) std::cin >> pages[i];

	for(int i = 0; i < n; i++){
	    for(int j = x; j >= price[i]; j--){
			dp[j] = std::max(dp[j], dp[j-price[i]]+pages[i]);
		}
	}
	
	ll ans = 0;
	for(int i = 0; i <= x; ++i) ans = std::max(ans, dp[i]);
	std::cout << ans;
}