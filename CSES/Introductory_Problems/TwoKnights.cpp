#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n;
  std::cin >> n;
  std::cout << 0 << '\n';
  for (long i = 2; i <= n; i++) {
    std::cout << ((i * i) * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2)) << '\n';
  }
 
}
