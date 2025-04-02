#include <bits/stdc++.h>

int main() 
{
	int n,m; std::cin >> n;
	std::vector<int> na(n);
	for(int i = 0; i < n; ++i) std::cin >> na[i];
	std::cin >> m;
	std::vector<int> ma(m);
	for(int i = 0; i < m; ++i) std::cin >> ma[i];

	int l = 0, r = 0, ml = 0, mr = 0, minDiff = INT_MAX;
	while( l < n && r < m){
		if(na[l] == ma[r]){
			std::cout << na[l] << " " << ma[r];
			return 0;
		}
		int curr = std::abs(na[l]-ma[r]);
		if (curr < minDiff){
			minDiff = curr;
			ml = l;
			mr = r;
		}
		if(na[l] < ma[r]) l++;
		else r++;
	}
	std::cout << na[ml] << " " << ma[mr];

	return 0;
}