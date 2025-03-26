#include <bits/stdc++.h>

int main(){
	std::ifstream in("planting.in");
	std::ofstream out("planting.out");
	int n; in >> n;
	std::vector<int> degree(n);
	for(int i = 0; i < n-1; ++i){
		int x,y; in >> x >> y;
		degree[x]++;
		degree[y]++;
	}
	out << *std::max_element(degree.begin(), degree.end())+1;	
}