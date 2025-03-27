#include <bits/stdc++.h>

bool check(std::vector<int>& order, std::vector<int>& h){
	int m = h.size();
	std::vector<int> cowPos(order.size(), -1);
	for(int i = 0; i < k; ++i) {
		if(order[i] != -1) cowPos[order[i]] = i;
	}

	int h_i = 0;
	for(int i = 0; i < n && h_i < m; i++){
		if(cowPos[hierachy[h_i]] != -1){
			if(i > cowPos[hierachy[h_i]]) return false;
			
			i = cowPos[hierachy[h_i]];
			h_i++;
		}
		else{
			while(i < n && order[i] != -1) i++;
			if(i == n) return false;

			order[i] = hierachy[h_i];
			cowPos[hierachy[h_i]] = i;
			h_i++;
		}
	}
	return true;
}

int main() {
	//std::ifstream in("milkorder.in");
	//std::ofstream out("milkorder.out");
	int n,m,k; std::cin >> n >> m >> k;
	std::vector<int> order(n,-1);
	std::vector<int> hierachy(m);

	for(int i = 0; i < m; ++i){
		int x; std::cin >> hierachy[i];
		hierachy[i]--;
	}
	
	for(int i = 0; i < k; i++){
		int x,y; std::cin >> x >> y;
		order[--y] = x;
	}

	for(int i = 0; i < n; ++i){
		if(order[i] == -1){
			order[i] = 0;
			if(check(order, hierachy)){
				std::cout << i+1;
				return 0;
			}
			order[i] = -1;
		}
	}
	return true;	
}