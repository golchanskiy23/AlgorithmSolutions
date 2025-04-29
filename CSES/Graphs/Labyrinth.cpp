#include <bits/stdc++.h>
#define N 1000

int n,m;
std::vector<std::string> graph;
bool b[N][N];
std::vector<std::vector<int>> d;
std::vector<std::vector<char> > steps(1000, std::vector<char>(1000));
std::stack<char> stack;

std::vector<int> dirX{0,-1,0,1} , dirY{-1,0,1,0};
std::string dir = "LURD";

void backtrack(std::pair<int, int> p, std::pair<int, int> start){
    if(p != start){
        char ch = steps[p.first][p.second];
        stack.push(ch);
        if(ch == 'L'){
            backtrack({p.first, p.second+1}, start);
        } else if(ch == 'U'){
            backtrack({p.first+1, p.second}, start);
        } else if(ch == 'R'){
            backtrack({p.first, p.second-1}, start);
        } else if(ch == 'D'){
            backtrack({p.first-1, p.second}, start);
        }
    }
}

bool bfs(std::pair<int, int> c, std::pair<int, int> end){
    std::queue<std::pair<int,int>> q;
    q.push(c);
    bool flag = false;
    d.assign(n, std::vector<int>(m));
    while(!q.empty()){
        auto head = q.front();
        q.pop();
        b[head.first][head.second] = true;
        if(head == end){
            flag = true;
            break;
        }
        for(int i = 0; i < 4; i++){
            int currX = head.first+dirX[i], currY = head.second+dirY[i];
            if(currX >= 0 && currY >= 0 && currX < n && currY < m && graph[currX][currY] != '#' && !b[currX][currY]){
                q.push({currX, currY});
                b[currX][currY] = true;
                steps[currX][currY] = dir[i];
            }
        }
    }
    if(flag){
        backtrack(end, c);
        return true;
    }
    return false;
}

int main(){
    std::cin >> n >> m;
    graph.resize(n);
    std::string s;
    for(int i = 0; i < n; i++){
        std::cin >> s;
        graph[i] = s;
    }
    
    std::pair<int, int> begin, end;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 'A'){
                begin.first = i; begin.second = j;
            } else if (graph[i][j] == 'B'){
                end.first = i; end.second = j;
            }
        }
    }
    
    if(bfs(begin, end)){
        std::cout << "YES" << '\n' << stack.size() << '\n';
        while(!stack.empty()){
            std::cout << stack.top();
            stack.pop();
        }
    } else{
        std::cout << "NO" << '\n';
    }
}