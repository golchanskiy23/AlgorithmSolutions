#include <bits/stdc++.h>

int main(){
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	int n, min = n; std::cin >> n;
	std::string string; std::cin >> string;
	for(int i = n; i >= 0; --i){
		std::set<std::string> set;
		bool flag = true;
		for(int j = 0; j < n-i+1; ++j){
			std::string curr = string.substr(j,i);
			if(set.count(curr) != 0){
				flag = false;
				break;
			}
			set.insert(curr);
		}
		if(flag) min = i;
	}
	std::cout << min;
}
