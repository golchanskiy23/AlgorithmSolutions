#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <set>
#include <string>
#include <map>

int main()
{
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    std::map<char, int> direction={{'N',0},{'S',1},{'E',2},{'W',3}};
    int x_dir[4]={0,0,1,-1};
    int y_dir[4]={1,-1,0,0};

    int x_pos=1001,y_pos=1001, curr_timestamp = 0, ans = INT_MAX;
    bool cross = false;
    std::map<std::pair<int,int>, int> board;
    board[std::make_pair(x_pos, y_pos)] = curr_timestamp;
    
    int n; std::cin >> n;
    for(int i = 0; i < n; ++i){
        char c; int r; std::cin >> c >> r;
        for(int j = 0; j < r; ++j){
            x_pos += x_dir[direction[c]];
            y_pos += y_dir[direction[c]];
            curr_timestamp++;
            if(board[std::make_pair(x_pos, y_pos)] != 0){
                cross = true;
                //std::cout << x_pos << " " << y_pos << " " << curr_timestamp << '\n';
                ans  = std::min(ans, curr_timestamp-board[std::make_pair(x_pos, y_pos)]);
            }
            board[std::make_pair(x_pos, y_pos)] = curr_timestamp;
        }
    }
    if(!cross) std::cout << -1;
    else std::cout << ans;
}