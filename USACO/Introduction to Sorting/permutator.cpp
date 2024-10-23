#include <bits/stdc++.h>
#define ll long long

int main(){
	ll  n; std::cin >> n;
	std::vector<ll> a(n), b(n);
	for(auto& c : a) std::cin >> c;
	for(auto& c : b) std::cin >> c;
	for(int i = 0; i < n; ++i){
		a[i] = a[i]*(i+1)*(n-i);
	}
	std::sort(a.begin(), a.end());
	ll ans = 0;
	std::sort(b.begin(), b.end());
	for(int i = 0; i < n; ++i){
		ans += (a[i]*b[n-i-1]);
	}
	std::cout << ans;
}
