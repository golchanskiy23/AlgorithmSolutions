#include <bits/stdc++.h>

int main(){
	int n; std::cin >> n;
	if(n <= 9){
		std::cout << 1;
		return 0;
	}
	std::vector<int> dp(n+1, INT_MAX);
	for(int i = 0;  i <= 9; i++) {dp[i] = 1;}
	for(int i = 10; i <= n; ++i){
		int curr = i;
		std::vector<int> digits;
		while(i > 0){
			int d = i % 10;
			if(d != 0) digits.push_back(d);
			i /= 10;
		}		
		
		for(int j = 0; j < digits.size(); ++j){
			dp[curr] = std::min(dp[curr], dp[curr-digits[j]]+1);
		}

		i = curr;
	}
	//for(auto& a : dp) std::cout << a << " ";
	std::cout << dp[n];

}