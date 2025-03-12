#include <bits/stdc++.h>
typedef long long ll;

int main(){
	ll n,m; std::cin >> n >> m;
	std::vector<int> v(n);
	std::map<ll,ll> map;
	for(int i = 0; i < n; ++i) {
		std::cin >> v[i];
		map[v[i]] = i;
	}
	std::vector<int> t(2);
	for(int i = 0; i < n; ++i){
		if(map.count(m-v[i]) != 0 && i != map[m-v[i]]){
			t[0] = i;
			t[1] = map[m-v[i]];
			std::sort(t.begin(), t.end());
			std::cout << t[0]+1 << " " << t[1]+1;
			return 0;
		}
	}
	std::cout << "IMPOSSIBLE";
	return 0;
}