#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::set<ll> set;
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    set.insert(val);
  }
  std::cout << set.size();
  return 0;
}
