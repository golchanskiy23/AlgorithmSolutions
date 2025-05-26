#include <bits/stdc++.h>
int n,m;
std::vector<int> grid[100005][2];
bool visited[100005];

void dfs(int i, int j){
    visited[i] = true;
    for(auto& a : grid[i][j]){
        if(!visited[a]) dfs(a,j);
    }
}

int main(){
    int a,b;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        std::cin >> a >> b;
        grid[a][0].push_back(b);
        grid[b][1].push_back(a);
    }
    // directed
    dfs(1,0);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            std::cout << "NO" << '\n';
            std::cout << 1 << " " << i;
            return 0;
        }
    }
    
    // reversed
    std::memset(visited, false, sizeof(visited));
    dfs(1,1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            std::cout << "NO" << '\n';
            std::cout << i << " " << 1;
            return 0;
        }
    }
    std::cout << "YES";
}