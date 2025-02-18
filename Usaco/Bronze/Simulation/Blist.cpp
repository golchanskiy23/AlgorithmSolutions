#include <iostream>
#include <vector>

int main()
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out","w", stdout);
    int n; std::cin >> n;
    std::vector<int> v(1001,0);
    for(int i = 0; i < n; ++i){
        int a,b,c; std::cin >> a >> b >> c;
        for(int j = a; j <= b; ++j){
            v[j] += c;
        }
    }
    int ans = 0;
    for(int i = 0; i < 1001; ++i){
        ans = std::max(ans,v[i]);
    }
    std::cout << ans;

    return 0;
}