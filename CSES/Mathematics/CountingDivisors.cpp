#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll q;
  std::cin >> q;
  std::vector<ll> divisors(1e6+1,0);
  for(int i = 1; i <= 1e6; i++)
    for(int j = i; j <= 1e6; j+=i)
      divisors[j]++;
  while(q--)
  {
    ll a;
    std::cin >> a;
    std::cout << divisors[a] << '\n';
  }
}