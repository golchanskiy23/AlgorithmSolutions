#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <set>
#include <string>


int main()
{
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);
    std::vector<std::string> ttt(3);
    for(int i = 0; i < 3; ++i) {
        std::cin >> ttt[i];
    }
    std::vector<std::set<char>> row(3),col(3), diag(2);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3;++j){
            row[i].insert(ttt[i][j]);
            col[j].insert(ttt[i][j]);
        }
    }
    for(int i = 0; i < 3; ++i){
        diag[0].insert(ttt[i][i]);
        diag[1].insert(ttt[i][2-i]);
    }
    std::set<std::set<char>> winners[4];
    for(auto& a : row) winners[a.size()].insert(a);
    for(auto& a : col) winners[a.size()].insert(a);
    for(auto& a : diag) winners[a.size()].insert(a);
    std::cout << winners[1].size() << '\n' << winners[2].size();

    return 0;
}