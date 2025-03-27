#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> v(n);
  for(int i = 0; i < n; i++)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());
  ll ans = 1;
  for(int i = 0; i < n; i++)
  {
    if(ans < v[i])
    {
      break;
    }
    ans += v[i];
  }
  std::cout << ans;
}