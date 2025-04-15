#include <bits/stdc++.h>

using ll = long long;

int main(){
	ll n, sum =0; std::cin >> n;
	std::vector<ll> v(n);
	// difference between s1 and s2 on [i,j]
	std::vector<std::vector<ll>> dp(n, std::vector<ll>(n,0));
	for(int i = 0; i < n; i++) {
	    std::cin >> v[i];
	    sum += v[i];
	    dp[i][i] = v[i];
	}
	for(int i = n-1; i >= 0; i--){
	    for(int j = i+1; j < n; j++){
	        if(i == j){
	            dp[i][j] = v[i];
	        }
	        dp[i][j] = std::max(v[i]-dp[i+1][j], v[j]-dp[i][j-1]);
	    }
	}
	
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << dp[i][j] << " ";
		}
		std::cout << '\n';
	}*/
	std::cout << (dp[0][n-1]+sum)/2;
}