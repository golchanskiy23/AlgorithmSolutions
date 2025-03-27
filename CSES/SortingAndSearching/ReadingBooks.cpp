#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n, max = 0, sum = 0;
  std::cin >> n;
  std::vector<ll> v(n);
  for(auto& a : v)
  {
    std::cin >> a;
    max = std::max(max,a);
    sum += a;
  }
  ll answer = (sum > 2*max) ? sum : 2*max;
  std::cout << answer;
}