#include <bits/stdc++.h>

const int INF = 1e9;

int main(){
	int n,m; std::cin >> n >> m;
	std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1,INF));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == j) dp[i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			
			for(int k = 0; k <= i; k++){
				dp[i][j] = std::min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
			}
			for(int k = 0; k <= j; k++){
				dp[i][j] = std::min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
			}
		}
	}

	
	std::cout << dp[n][m];
}