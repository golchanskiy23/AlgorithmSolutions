#include <bits/stdc++.h>

int main(){
	int n; std::cin >> n;
	std::vector<long long> v(n);
	for(int i = 0; i < n; ++i) std::cin >> v[i];
	std::sort(v.begin(), v.end());
	long long max = 0, count = 0;
	for(int i = 0; i < n; ++i){
		if(v[i]*(n-i) > max){
			max = v[i]*(n-i);
			count = v[i];
		}
	}
	std::cout << max << " " << count;;
}
