#include <bits/stdc++.h>

int main(){
	int n; std::cin >> n;
	const int INF = 2e9;
	// dp[i] - наим число на префиксе длины i
	std::vector<int> dp(n+1, INF), v(n);
	for(int i = 0; i < n; i++) std::cin >> v[i];
	dp[0] = -INF;
	for(int i = 0; i < n; i++){
		int l = std::upper_bound(dp.begin(), dp.end(),v[i])-dp.begin();
		if(dp[l-1] < v[i] && v[i] < dp[l]){
			dp[l] = v[i];
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		if(dp[i] != -INF && dp[i] != INF){
			ans++;
		}
	}
	std::cout  << ans;
}