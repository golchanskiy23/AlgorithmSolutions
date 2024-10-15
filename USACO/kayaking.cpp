#include <bits/stdc++.h>

int main()
{
    int n; std::cin >> n;
    std::vector<int> v(2*n,0);
    for(int i=0; i < 2*n; ++i){
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    int ans = INT_MAX;
    for(int i = 0; i < 2*n; ++i){
        for(int j = i+1; j < 2*n; ++j){
            int cur = 0, cnt = 0, last = -1;
            for(int k = 0;k < 2*n; ++k){
                if(k == i || k == j) continue;
                if(++cnt == 2){
                    cur += (v[k]-v[last]);
                    cnt = 0;
                }
                else{
                    last = k;
                }
            }
            ans = std::min(ans, cur);
        }
    }
    std::cout << ans << '\n';
}
