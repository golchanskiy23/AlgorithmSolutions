#include <bits/stdc++.h>

int main(){
	int n,m,k; std::cin >> n >> m >> k;
	char table[n][m];
	int row[8] = {-1,-1,-1,0,1,1,1,0};
	int col[8] = {-1,0,1,1,1,0,-1,-1};
	for(int i = 0; i < k; ++i){
		int a,b; std::cin >> a >> b;
		table[a-1][b-1] = '-';
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(table[i][j] == '-') std::cout << '*';
			else{
				int t = 0;
				for(int k = 0; k < 8; ++k){
					if(i+row[k] >= 0 && j+col[k] >= 0 && i+row[k] < n && j+col[k] < m){
						if(table[i+row[k]][j+col[k]] == '-') ++t;
					}
				}
				std::cout << t;
			}

			if(j==m-1) std::cout << '\n';
			else std::cout << " ";
		}
	}
}
