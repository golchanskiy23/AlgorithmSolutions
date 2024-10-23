#include <bits/stdc++.h>

int main(){
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	int n; std::cin >> n;
	std::unordered_map<std::string, int> map;
	for(int i = 0; i < n; ++i){
		std::string str; std::cin >> str;
		int a; std::cin >> a;
		map[str] += a;
	}
	std::vector<std::pair<int, std::string>> cows;
	for (std::pair<std::string, int> t : map) { cows.push_back({t.second, t.first}); }
	std::sort(cows.begin(), cows.end());
	int ind = 0, COW_NUM = 7;
	if (cows.size() == COW_NUM) {
		while (ind < cows.size() && cows[ind].first == cows[0].first) { ind++; }
	}
	if (ind < cows.size() &&
	    (ind + 1 == cows.size() || cows[ind].first != cows[ind + 1].first)) {
		std::cout << cows[ind].second << '\n';
	} else {
		std::cout  << "Tie" << '\n';
	}
}
