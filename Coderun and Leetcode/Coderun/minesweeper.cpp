#include <iostream>
#include <string>
#include <vector>
#include <set>

int x_dir[8] = {-1,-1,0,1,1,1,0,-1};
int y_dir[8] = {0,1,1,1,0,-1,-1,-1};

int main() 
{
	int n,m,k;std::cin >> n >> m >> k;
	std::set<std::pair<int,int>> s;
	std::vector<std::vector<int>> v(n, std::vector<int>(m, 0));
	for(int i = 0; i < k ; ++i){
		int a,b; std::cin >> a >> b;
		s.insert(std::make_pair(a-1,b-1));
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!s.count(std::make_pair(i,j))){
				for(int l = 0;l < 8; ++l){
					int curr_x = i, curr_y = j;
					curr_x += x_dir[l];
					curr_y += y_dir[l];
					if(curr_x >= 0 && curr_x < n && curr_y >= 0 && curr_y < m){
						if(s.count(std::make_pair(curr_x,curr_y))){
							v[i][j]++;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(s.count(std::make_pair(i,j))){
				std::cout << "* ";
			}
			else std::cout << v[i][j] << " ";
		}
		std::cout << '\n';
	}


	return 0;
}