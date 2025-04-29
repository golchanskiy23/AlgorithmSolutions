#include <bits/stdc++.h>

bool visited[1000][1000];
std::vector<std::string> v;
int n,m;

std::vector<int> xDir{0,-1,0,1}, yDir{-1,0,1,0};

void dfs(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || v[x][y] == '#'){
		return;		
	}
	visited[x][y] = true;
	for(int k = 0; k < 8; k++){
		dfs(x+xDir[k],y+yDir[k]);
	}
}

int main(){
    std::cin >> n >> m;
	v.resize(n);
	std::string s;
	for(int i = 0; i < n; i++){
		std::cin >> s;
		v[i] = s;
	}
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			visited[i][j] = false;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		    if(v[i][j] != '#' && !visited[i][j]){
		      dfs(i,j);
		      ans++;
		    }
		}
	}
	std::cout << ans;
}