#include <bits/stdc++.h>
typedef long long ll;

ll rec(int idx, int n, ll sum1, ll sum2, const std::vector<ll>& v){
    if(idx == n) return std::abs(sum1- sum2);
    std::cout << sum1 << " " << sum2 << '\n';
    return std::min(rec(idx+1, n, sum1 + v[idx], sum2,v),
    rec(idx+1, n, sum1, sum2+ v[idx],v));
}

int main()
{
    ll n; std::cin >> n;
    std::vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }
    std::cout << rec(0,n,0,0,v);
}