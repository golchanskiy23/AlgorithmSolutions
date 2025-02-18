#include <iostream>
#include <vector>
#include <cmath>

int square(int xi, int xj, int yi, int yj){
    int c = ((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
    return c;
}

int main()
{
    int n; std::cin >> n;
    std::vector<int> x(n,0), y(n,0);
    int ans = 0;
    for(int i = 0; i < n; ++i) std::cin >> x[i];
    for(int i = 0; i < n; ++i) std::cin >> y[i];
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
                ans = std::max(square(x[i],x[j],y[i],y[j]), ans);
            }
    }
    
    std::cout << ans;

    return 0;
}