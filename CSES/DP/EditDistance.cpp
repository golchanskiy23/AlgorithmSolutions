#include <bits/stdc++.h>

int main(){
	std::string s1,s2; std::cin >> s1 >> s2;
	int n = s1.size(), m = s2.size(), substitutionCost = 0;
	std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1,0));
	
	for(int i = 0; i <= n; ++i) dp[i][0] = i;
	for(int j = 0; j <= m; ++j) dp[0][j] = j;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s1[i-1] != s2[j-1]){
				substitutionCost = 1;
			} else{substitutionCost = 0;}
			dp[i][j] = std::min(dp[i-1][j]+1 , std::min(dp[i][j-1]+1, dp[i-1][j-1]+substitutionCost));
		}
	}
	/*for(int i = 0; i <=n; i++){
	    for(int j = 0; j <= m; j++){
	        std::cout << dp[i][j] << " ";
	    }
	    std::cout << '\n';
	}*/
	std::cout << dp[n][m];
}