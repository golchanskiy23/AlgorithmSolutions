#include <bits/stdc++.h>
typedef long long ll;

ll func(const std::vector<ll>& v, ll k, ll n) {
    ll lastDay = v[0], cost = k+1;
    for(auto& d : v){
        // continue chain
        if(d-lastDay < k+1) {
            cost += (d-lastDay);
        }
        else {
            cost += (k+1); // sign new contract
        }
	lastDay = d;
    }
    return cost;
}

int main(){
	ll n,k; std::cin >> n >> k;
	std::vector<ll> v(n);
	for(int i = 0; i<n; ++i) std::cin >> v[i];
	
	std::cout << func(v,k,n);
}