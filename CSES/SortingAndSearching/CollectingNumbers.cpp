#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> v(n);
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    v[--val] = i;
  }
  ll count=  1;
  for(int i = 1; i < n; i++)
  {
    if(v[i-1] > v[i]) ++count;
  }
  std::cout << count;
}
