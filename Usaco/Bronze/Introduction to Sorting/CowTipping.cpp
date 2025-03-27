#include <bits/stdc++.h>

int main(){
	std::ifstream in("cowtip.in");
	std::ofstream out("cowtip.out");
	int n, swaps = 0; in >> n;
	std::vector<std::string> v(n);
	for(int i = 0; i < n; ++i){
		std::string s; in >> s;
		v[i] = s;
	}

	for(int i = n-1; i >= 0; i--){
		for(int j = n-1; j >= 0; j--){
			
			if(v[i][j] == '1'){
				swaps++;
				for(int a = 0; a <= i; a++){
					for(int b = 0; b<= j; b++){
						if(v[a][b] == '1'){
							v[a][b] = '0';
						} else{
							v[a][b] = '1';
						}
					}
				}
			}
			
		}
	}
	out << swaps;
}