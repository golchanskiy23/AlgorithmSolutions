#include <iostream>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited);

std::vector<int> tmp;

int main() 
{
    int v, e;
    std::cin >> v >> e;

    // Список смежности для представления графа
    std::vector<std::vector<int>> adjList(v + 1);
    std::vector<bool> visited(v + 1, false);
    std::vector<std::vector<int>> ans;

    for(int i = 0; i < e; ++i){
        int f, s;
        std::cin >> f >> s;
        adjList[f].push_back(s);
        adjList[s].push_back(f);
    }

    for(int i = 1; i <= v; ++i){
        if(!visited[i]){
            tmp.clear();
            dfs(i, adjList, visited);
            ans.push_back(tmp);
        }
    }

    std::cout << ans.size() << '\n';
    for(auto& a : ans){
        std::cout << a.size() << '\n';
        for(auto& b : a) std::cout << b << " ";
        std::cout << '\n';
    }

    return 0;
}

void dfs(int v, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    visited[v] = true;
    tmp.push_back(v);
    for (int u : adjList[v]) {
        if (!visited[u]) {
            dfs(u, adjList, visited);
        }
    }
}
