#include <bits/stdc++.h>

int main(){
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	int n; std::cin >> n;
	std::vector<int> v(n);
	for(auto& a : v) std::cin >> a;
	int k = v[n-1], ans = n-1;
	for(int i= n-2; i >= 0; i--){
		if(v[i] < v[i+1]){
			ans = i;
		}
		else break;
	}
	std::cout << ans;
}
