#include <bits/stdc++.h>
using ll = long long;
int main()
{
  ll n; std::cin >> n;
  std::vector<ll> v(n),prefix(n+1,0); for(auto& a : v) std::cin >> a;
  for(ll i = 1; i <= n; ++i)
    prefix[i]=prefix[i-1]+v[i-1];
  ll min = prefix[0], ans = -1e9;
  for(ll i = 1; i <= n; ++i)
  {
    ans = std::max(ans,prefix[i]-min);
    min = std::min(min,prefix[i]);
  }
  std::cout << ans;
}
