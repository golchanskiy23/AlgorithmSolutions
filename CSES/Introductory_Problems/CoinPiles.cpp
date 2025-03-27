#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  while(n--)
  {
    ll a,b;
    std::cin >> a >> b;
    if((a+b)%3==0 && (a+b)/3 >= (std::abs(a-b)))
    {
      std::cout << "YES" << '\n';
      continue;
    }
    else
    {
      std::cout << "NO" << '\n';
    }
  }
 
}