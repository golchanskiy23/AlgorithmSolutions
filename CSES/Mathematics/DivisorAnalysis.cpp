#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9 + 7;
 
ll expo(ll base, ll pow)
{
  ll ans = 1;
  while (pow)
  {
    if (pow & 1) ans = ans * base % MOD;
    base = base * base % MOD;
    pow >>= 1;
  }
  return ans;
}
 
int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  ll n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> v(n);
  for (int i = 0; i < n; i++) std::cin >> v[i].first >> v[i].second;
  ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;
  for (int i = 0; i < n; i++) {
    div_cnt = div_cnt * (v[i].second + 1) % MOD;
    div_sum = div_sum * (expo(v[i].first, v[i].second + 1) - 1) % MOD * expo(v[i].first - 1, MOD - 2) % MOD;
    div_prod = expo(div_prod, v[i].second + 1) * expo(expo(v[i].first, (v[i].second * (v[i].second + 1) / 2)), div_cnt2) % MOD;
    div_cnt2 = div_cnt2 * (v[i].second + 1) % (MOD - 1);
  }
  std::cout << div_cnt << ' ' << div_sum << ' ' << div_prod;
  return 0;
}