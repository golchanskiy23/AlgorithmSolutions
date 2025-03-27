#include <bits/stdc++.h>
using ll = long long;
 
bool check_func(ll middle, ll n, ll k, const std::vector<ll>& v)
{
  ll groups = 0, sum = 0;
  for(int i = 0; i < n; i++)
  {
    if(v[i]>middle)
    {
      return false;
    }
    if(sum + v[i] > middle)
    {
      ++groups;
      sum = 0;
    }
    sum += v[i];
  }
  if(sum > 0)
  {
    ++groups;
  }
  return groups <= k;
}
 
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ll n,k;
  std::cin >> n >> k;
  std::vector<ll> v(n);
  ll sum_ = 0;
  for(int i = 0; i < n; i++)
  {
    std::cin >> v[i];
    sum_ += v[i];
  }
  ll left = 0, right = sum_, ans = 0;
  while(left <= right)
  {
    ll mid = (left+right)/2;
    if(check_func(mid, n, k, v))
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