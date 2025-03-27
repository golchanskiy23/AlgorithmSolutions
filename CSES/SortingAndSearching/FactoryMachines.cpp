#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n,t;
  std::cin >> n >> t;
  std::vector<ll> v(n);
  for(auto& a : v)
    std::cin >> a;
 
  ll left = 0, right = 1e18, ans = 0;
  while(left <= right)
  {
    ll mid = (right+left)/2;
    ll sum = 0;
    for(auto& a : v)
    {
      sum += (mid/a);
      if(sum >= t) break;
    }
    if(sum >= t)
    {
      ans = mid;
      right = mid-1;
    }
    else
    {
      left = mid+1;
    }
  }
  std::cout << ans;
}