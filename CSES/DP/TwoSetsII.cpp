#include <bits/stdc++.h>

const int MOD = 1000000007;
std::vector<int> dp(65000, 0);

int main(){
    int n; std::cin >> n;
    int target = (n+1)*n/2;
    if(target%2==1){
    	std::cout << 0;
	return 0;
    }
    int sum = target/2;
    dp[0] = 1;
    for(int i= 1; i< n; i++){
    	for(int j = sum; j >= i; j--){
		dp[j] += dp[j-i];
		dp[j] %= MOD;
	}
    }
    
    std::cout << dp[target/2];
}
