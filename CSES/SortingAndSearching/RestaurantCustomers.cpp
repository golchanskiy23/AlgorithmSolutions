#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<std::pair<ll,ll>> prefix;
  for(int i = 0; i < n; i++)
  {
    ll a,b;
    std::cin >> a >> b;
    prefix.push_back({a,1}); prefix.push_back({b,-1});
  }
  std::sort(prefix.begin(), prefix.end());
 
  ll max = 0, curr = 0;
  for(auto& a : prefix)
  {
    curr += a.second;
    max = std::max(max, curr);
  }
  std::cout << max << '\n';
  return 0;
}
