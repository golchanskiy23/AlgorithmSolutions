#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n, m;
  std::cin >> n >> m;
  std::multiset< ll > available_set;
  for (int i = 0; i < n; i++) {
    ll val;
    std::cin >> val;
    available_set.insert(val);
  }
 
  for(int i = 0; i < m; i++)
  {
    ll val;
    std::cin >> val;
    auto it = available_set.upper_bound(val);
    if(it==available_set.begin())
    {
      std::cout << -1 << '\n';
    }
    else
    {
      std::cout << *(--it) << '\n';
      available_set.erase(it);
    }
  }
 
  return 0;
}
