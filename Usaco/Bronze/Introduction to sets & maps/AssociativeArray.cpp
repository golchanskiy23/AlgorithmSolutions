#include <bits/stdc++.h>
typedef long long ll;

int main(){
    ll n,a; std::cin >> n;
    std::map<ll,ll> m;
    for(int i = 0; i < n; ++i){
        std::cin >> a;
        ll k;
        if(a == 1) {
            std::cin >> k;
            std::cout << m[k] << '\n';
        }
        else{
            ll v; std::cin >> k >> v;
            m[k] = v;
        }
    }
    return 0;
}