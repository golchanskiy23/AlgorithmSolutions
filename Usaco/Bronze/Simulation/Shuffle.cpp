#include <iostream>
#include <vector>

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int N; std::cin >> N;
    std::vector<int> temp(N+1), orig(N+1),idx(N+1);
    for(int i = 1; i <= N; ++i) std::cin >> idx[i];
    for(int i = 1; i <= N; ++i) std::cin >> orig[i];
    for(int i = 0; i <= 2; ++i){
        for(int i =1; i <= N; ++i) temp[i] = orig[idx[i]];
        for(int i =1; i <= N; ++i) orig[i] = temp[i];
    }
    for(int i = 1; i <= N;++i){
        std::cout << orig[i] << '\n';
    }
    return 0;
}