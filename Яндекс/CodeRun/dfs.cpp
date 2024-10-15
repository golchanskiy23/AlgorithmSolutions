#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int v, const std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, std::vector<int>& ans);

int main() 
{
    int v, e;
    std::cin >> v >> e;
    
    std::vector<std::vector<int>> matrix(v + 1, std::vector<int>(v + 1, 0));
    std::vector<bool> visited(v + 1, false);
    std::vector<int> ans;

    for(int i = 0; i < e; ++i){
        int f, s;
        std::cin >> f >> s;
        matrix[f][s] = 1;
        matrix[s][f] = 1;
    }
    dfs(1, matrix, visited, ans);
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for(auto& a : ans) std::cout << a << " ";
    
    return 0;
}

void dfs(int v, const std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, std::vector<int>& ans) {
    visited[v] = true;
    ans.push_back(v);
    for (int u = 1; u < matrix[v].size(); ++u) {
        if (!visited[u] && matrix[v][u] == 1) {
            dfs(u, matrix, visited, ans);
        }
    }
}
