#include <bits/stdc++.h>
namespace{
int explosion_sum(int start, int dest, int n, const std::vector<int>& v){
        int prev = start, radius = 1;
        while(true){
                int next = prev;
                while(next+dest >= 0 && next+dest < n && std::abs(v[next+dest]-v[prev]) <= radius){
                        next += dest;
                }
                if(next == prev) break;
                prev = next;
                ++radius;
        }
        return std::abs(prev-start);
}
}

int main(){
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
        int n; std::cin >> n;
        std::vector<int> v(n);
        for(auto&a : v) std::cin >> a;
        std::sort(v.begin(), v.end());
        int max_= 0;
        for(int i = 0; i < n; ++i){
                max_ = std::max(max_, explosion_sum(i,1, n, v)+explosion_sum(i,-1, n,v)+1);
        }
        std::cout << max_;
}
