#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<bool> arr(n, false);
  std::vector<ll> v;
  for(int i = 0; i < n-1; i++)
  {
    ll val;
    std::cin >> val;
    arr[val] = true;
  }
  for(int i = 1; i < n;  i++)
  {
    if(!arr[i])
      v.push_back(i);
  }
  if(v.empty())
    v.push_back(n);
  std::cout << v[0];
}