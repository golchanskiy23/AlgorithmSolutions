#include <bits/stdc++.h>
#define ll long long

int main(){
	ll n; std::cin >> n;
	std::map<ll,ll> map;
	for(ll i = 0; i < n; ++i){
		ll a; std::cin >> a;
		if(a == 1){
			ll b; std::cin >> b;
			std::cout << map[b] << '\n';
		}
		else {
			ll b,c; std::cin >> b >> c;
			map[b] = c;
		}
	}
}
