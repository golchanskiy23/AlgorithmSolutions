#include <bits/stdc++.h>
typedef long long ll;

int main(){
	int n, even = 0, odd = 0; std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
	    std::cin >> v[i];
	    if(v[i]%2==0) even++;
	    else odd++;
	}
	
	while(odd > even){
	    odd -= 2;
	    even++;
	}

	if(odd == even){
		std::cout << 2*odd;
		return 0;
	}
	int ans = 2*odd+1;
	std::cout << ans;
}