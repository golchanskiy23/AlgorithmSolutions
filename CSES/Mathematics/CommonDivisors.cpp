#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::vector<ll> divisors(1000001,0), answers;
  for(int i = 0; i < n; i++)
  {
    ll val;
    std::cin >> val;
    divisors[val]++;
  }
 
  for(int i = 1e6; i >= 1; i--)
  {
    ll div_count = 0;
    for(int j = i; j <= 1e6; j+=i)
    {
      div_count += divisors[j];
      if(div_count>=2) {
        std::cout << i;
        return 0;
      }
    }
  }
 
}
