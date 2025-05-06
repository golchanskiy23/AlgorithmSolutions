#include <bits/stdc++.h>
#define MAXN 1000
#define f first
#define s second

using pii = std::pair<int, int>;
using vvi = std::vector<std::vector<int>>;
using vs = std::vector<std::string>;
using vi = std::vector<int>;
using vvc = std::vector<std::vector<char>>;
using vc = std::vector<char>;

int n,m;
pii endPosition;
vs graph(MAXN);
vvi monsterTime(MAXN, vi(MAXN, INT_MAX));
vvi personTime(MAXN, vi(MAXN, INT_MAX));
vvc steps(MAXN, vc(MAXN, '.'));
vi dirX{0,-1,0,1}, dirY{-1,0,1,0};
std::string dir = "LURD";

std::stack<char> stack;

bool isValid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || graph[x][y] == '#') return false;
    return true;
}

bool isBoundary(int x, int y){
    return x == 0 || y == 0 || x == n-1 || y == m-1;
}

void monsterBFS(std::queue<pii>& mq){
    while(!mq.empty()){
        auto head = mq.front();
        mq.pop();
        for(int i = 0; i < 4; i++){
            int nextX = head.f+dirX[i] , nextY=head.s+dirY[i];
            if(isValid(nextX, nextY) && monsterTime[nextX][nextY] > monsterTime[head.f][head.s]+1){
                monsterTime[nextX][nextY] = monsterTime[head.f][head.s]+1;
                mq.push({nextX, nextY});
            }
        }
    }
}

bool personBFS(const pii& startPosition){
    std::queue<pii> pq;
    pq.push(startPosition);
    while(!pq.empty()){
        auto head = pq.front();
        pq.pop();
        if(isBoundary(head.f, head.s)){
            endPosition.f = head.f;
            endPosition.s = head.s;
            return true;
        }
        for(int i = 0; i < 4; i++){
            int nextX = head.f+dirX[i], nextY = head.s+dirY[i];
            if(isValid(nextX, nextY) && personTime[nextX][nextY] > personTime[head.f][head.s]+1){
                if(monsterTime[nextX][nextY] > personTime[head.f][head.s]+1){
                    personTime[nextX][nextY] = personTime[head.f][head.s]+1;
                    steps[nextX][nextY] = dir[i];
                    pq.push({nextX, nextY});
                }
            }
        }
    }
    
    return false;
}

void backtrack(const pii& startPosition, pii endPosition){
    if(startPosition != endPosition){
        char c = steps[endPosition.f][endPosition.s];
        stack.push(c);
        if(c == 'L'){
            backtrack(startPosition, {endPosition.f, endPosition.s+1});
        } else if(c == 'U'){
            backtrack(startPosition, {endPosition.f+1, endPosition.s});
        } else if(c == 'R'){
            backtrack(startPosition, {endPosition.f, endPosition.s-1});
        } else{
            backtrack(startPosition, {endPosition.f-1, endPosition.s});
        }
    }
}

int main(){
    std::cin >> n >> m;
    std::string tmp;
    for(int i = 0; i < n; i++){
        std::cin >> tmp;
        graph[i] = tmp;
    }
    
    std::queue<pii> mq;
    pii startPosition;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 'A'){
                personTime[i][j] = 0;
                startPosition.f = i;
                startPosition.s = j;
            } else if(graph[i][j] == 'M'){
                monsterTime[i][j] = 0;
                mq.push({i,j});
            }
        }
    }
    
    monsterBFS(mq);
    if(personBFS(startPosition)){
        backtrack(startPosition, endPosition);
        std::cout << "YES" << '\n' << stack.size() << '\n';
        while(!stack.empty()){
            std::cout << stack.top();
            stack.pop();
        }
    } else{
        std::cout << "NO";
    }
    return 0;
}