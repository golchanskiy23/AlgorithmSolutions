#include <bits/stdc++.h>
using ll = long long;

int main()
{
    ll n,q, start, end; std::cin >> n >> q;
    std::vector<ll> v(n), prefix(n+1, 0);
    for(int i = 0; i < n; i++) std::cin >> v[i];
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1]+v[i-1];
    for(int i = 0; i < q; i++){
        std::cin >> start >> end;
        std::cout << prefix[end]-prefix[start-1] << '\n';
    }
}