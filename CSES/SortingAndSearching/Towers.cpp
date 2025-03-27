#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  std::multiset<ll> set;
  ll n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    auto it = set.upper_bound(val);
    if(it != set.end())
    {
      set.erase(it);
      set.insert(val);
    }
    else
    {
      set.insert(val);
    }
  }
  std::cout << set.size();
}
