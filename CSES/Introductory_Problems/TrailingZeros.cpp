#include <bits/stdc++.h>
using ll = long long;
 
int main()
{
  ll n, curr = 5, ans = 0;
  std::cin >> n;
  while(curr <= n)
  {
    ans += n/curr;
    curr *= 5;
  }
  std::cout << ans;
}