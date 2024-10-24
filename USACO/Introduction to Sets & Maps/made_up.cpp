#include <bits/stdc++.h>

int main(){
	int n; std::cin >> n;
	std::vector<int> a(n), b(n), c(n);
	std::map<int, int> map;
	//std::multiset<int> set;
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
		map[a[i]]++;
		//set.insert(a[i]);
	}
	for(int i = 0; i < n; ++i){
		std::cin >> b[i];
	}
	for(int i = 0; i < n; ++i){ 
                std::cin >> c[i];
        }
	long long ans = 0;
	for(int j = 0; j < n; ++j){
		int curr = b[c[j]-1];
		ans += map[curr];
		//ans += set.count(curr);
	}
	std::cout << ans;
}
