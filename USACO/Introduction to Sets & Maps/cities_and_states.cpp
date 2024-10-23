#include <bits/stdc++.h>

int main(){
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
	int n, ans = 0; std::cin >> n;
	std::vector<std::pair<std::string, std::string>> set;
	for(int i = 0; i < n; ++i){
		std::string f,s; std::cin >> f >> s;
		set.push_back({f.substr(0,2), s});
	}
	std::map<std::string, int> map;
	for(const auto& a : set){
		if(a.first != a.second) ans += map[a.second+a.first];
		map[a.first+a.second]++;
	}
	std::cout << ans << '\n';
}
