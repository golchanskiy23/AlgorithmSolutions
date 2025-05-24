#include <bits/stdc++.h>
using ll = long long;
 
const int MAXD = 30;  
int n, q;

int jump(int a, int d, const std::vector<std::vector<int>>& parent) {
	for (int i = 0; i < MAXD; i++)
		if (d & (1 << i)) a = parent[a][i];
	return a;
}
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> q;
	std::vector<std::vector<int>> parent(n+1, std::vector<int>(MAXD, 0));
	for (int i = 1; i <= n; i++) { std::cin >> parent[i][0]; }
	
	for (int d = 1; d < MAXD; d++)
		for (int i = 1; i <= n; i++) { parent[i][d] = parent[parent[i][d - 1]][d - 1]; }
	while (q--) {
		int a, d;
		std::cin >> a >> d;
		std::cout << jump(a, d, parent) << '\n';
	}
}
